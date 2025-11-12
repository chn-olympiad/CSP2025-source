#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
int C(int n,int m){
	int sum=1;
	for(int i=n;i>=m+1;i--){
		sum=sum*i%mod;
	}
	int num=1;
	for(int i=1;i<=n-m;i++){
		num=num*i%mod;
	}
	return (sum+mod)/num%mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	int c[505];
	int cc=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0) cc++;
	}
	int nn=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1') nn++;
	}
	if(nn==n&&cc==0){
		int sum[505]={0};
		int cnt=0;
		for(int i=m;i<=n;i++){
			sum[i]=1;
			for(int j=1;j<=n;j++){
				sum[i]=sum[i]*j%mod;
			}
			cnt=(cnt+sum[i])%mod;
		}
		cout<<cnt;
	}
	else if(nn==n&&cc!=0){
		int xyz=0;
		if(n-cc<m) cout<<"0";
		else{
			for(int i=m;i<=n-cc;i++){
				xyz=(xyz+C(n,i))%mod;
			}
		}
		cout<<xyz;
	}
	else{
		cout<<"0";
	}
	return 0;
}
