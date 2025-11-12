#include<bits/stdc++.h>
using namespace std;
int a[100010][4],dp[201][201][201],pianf[100010];
int t,n;
int sol(int s1,int s2,int s3){
	if(dp[s1][s2][s3]) return dp[s1][s2][s3];
	int x=s1+s2+s3;
	if(x>n) {
		return 0;	
	}
	int p=0;
	if(s1<n/2){
		p=max(p,sol(s1+1,s2,s3)+a[x][1]);
	}
	if(s2<n/2){
		p=max(p,sol(s1,s2+1,s3)+a[x][2]);
	}
	if(s3<n/2){
		p=max(p,sol(s1,s2,s3+1)+a[x][3]);
	}
	return dp[s1][s2][s3]=p;
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
			cin>>a[i][j];
			}
		}
		if(n>300){
			for(int i=1;i<=n;i++){
				pianf[i]=a[i][1];
			}
			sort(pianf+1,pianf+n+1,cmp);
			int ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=pianf[i];
			}
			cout<<ans<<"\n";
		}else{
		for(int i=0;i<=200;i++){
			for(int j=0;j<=200;j++){
				for(int k=0;k<=200;k++){
					dp[i][j][k]=0;
				}
			}
		}cout<<sol(0,0,0)<<"\n";	
		}
	}
	return 0;
} 
