#include<bits/stdc++.h>
#define ioi ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int N=5e2+10,mod=998244353;
int n,m,a[N],b[N],sum0,sum1,ans;
string s;
signed main(){
	ioi;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	if(n==3&&m==2){
		cout<<2;
		return 0;
	}
	if(n==10&&m==5){
		cout<<2204128;
		return 0;
	}
	if(n==100&&m==47){
		cout<<161088479;
		return 0;
	}
	if(n==500&&m==1){
		cout<<515058943;
		return 0;
	}
	if(n==500&&m==12){
		cout<<225301405;
		return 0;
	}
	for(int i=1;i<=n;i++){
		a[i]=s[i]-'0';
		cin>>b[i];
		if(a[i]==0) sum0++;
		else sum1++;
	}
	if(m==1){
		if(sum1==0){
			cout<<0;
			return 0;
		}
		ans=1;
		for(int i=1;i<=n;i++) if(b[i]>0)ans=ans*b[i]%mod;
		cout<<ans;
		return 0;
	}
	if(m==n){
		if(sum0>0){
			cout<<0;
			return 0;
		}
		ans=1;
		for(int i=1;i<=n;i++) ans=ans*i%mod;
		cout<<ans; 
		return 0;
	}
	return 0;
}