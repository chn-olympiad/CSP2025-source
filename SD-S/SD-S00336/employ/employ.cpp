#include<iostream>
#include<cstdio>
using namespace std;
int n,m,c[20],dp[20][262146],chice[20],mi[32],num;
string s;
int ksm(int a,int b){
	if(a==2) return mi[b];
	int ans=1;
	for(int i=1;i<=b;i++) ans*=a;
	return ans;
}
void turnstring(int a){
	for(int i=0;i<n;i++){
		if(int(a&1)==1){
			chice[i]=1;
		}
		else chice[i]=0;
		a>>=1;
	}
}
void turnnum(){
	int ans=0;
	for(int i=0;i<n;i++){
		ans+=ksm(2,i)*chice[i];
	}
	num=ans;
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	mi[0]=1;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		mi[i]=mi[i-1]*2;
	}
	dp[0][0]=1;
	for(int i=0;i<=n;i++){
		for(int j=0;j<ksm(2,n);j++){
			if(dp[i][j]==0) continue;
			turnstring(j);
			for(int k=0;k<n;k++){
				if(chice[k]==1) continue;
				int dth=0;
				for(int o=0;o<n;o++){
					if(chice[o]==1) dth++;
				}
				chice[k]=1;
				turnnum();
				if(s[i]=='0' || dth-i>=c[k]){
					dp[i][num]+=dp[i][j];
					//cout<<1;
				}
				else{
					dp[i+1][num]+=dp[i][j];
					//cout<<2;
				}
				chice[k]=0;
			}
		}
	}
	int ans=0; 
	for(int i=0;i<=n;i++){
		for(int j=0;j<ksm(2,n);j++){
			cout<<dp[i][j]<<' ';
		}
		cout<<endl;
	}
	for(int i=m;i<=n;i++){
		ans+=dp[i][ksm(2,n+1)-1];
	}
	cout<<ans;
	return 0;
} 
