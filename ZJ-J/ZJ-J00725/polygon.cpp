#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
using namespace std;
const int N=1e6+5;
const int M=3e3+5;
const int eps=1e-6;
const int mod=998244353;
int read(){
	int k=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		k=k*10+ch-'0';
		ch=getchar();
	}
	return k*f;
}
int a[N],dp[M][M],Max[M][M];
void solve(){
	int n=read();
	bool f=0;
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]!=1)f=1;
	}
	if(n<=3){
		if(n<3){
			cout<<"0\n";
		}
		else{
			int Maxn=max(a[1],max(a[2],a[3]));
			if(a[1]+a[2]+a[3]>Maxn)cout<<"1\n";
			else cout<<"0\n";
		}
		return ;
	}
	if(f){
		cout<<"0\n";
		return ;
	}
	int ans=n*(n-1)*(n-2)/6;int tmp=n*(n-1)*(n-2)/6;
	ans%=mod;
	for(int i=4;i<=n;i++)ans=(ans+tmp*(n-i+1)/i%mod)%mod,tmp=tmp*(n-i+1)/i;
	cout<<ans%mod<<'\n';
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--)solve();
	return 0;
}

