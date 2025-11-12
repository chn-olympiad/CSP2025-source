#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
	ll sum=0,f=1;char c=getchar();
	while('0'>c||c>'9'){if(c=='-') f=-f;c=getchar();}
	while('0'<=c&&c<='9'){sum=sum*10+c-'0';c=getchar();}
	return sum*f;
}
const ll N=1005;
const ll mod=998244353;
ll n,ans,maxn;
ll a[N],C[N];
ll f[N][N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		maxn+=a[i];
	}
	sort(a+1,a+n+1);
	ll sum=1;
	for(int i=1;i<=n;i++){
		C[i]=sum;
		sum<<=1;
		sum%=mod;
	}
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=a[i];j<=5000;j++){
			f[i][j]+=f[i-1][j-a[i]];
			f[i][j]%=mod;
		}
		for(int j=0;j<=5000;j++){
			f[i][j]+=f[i-1][j];
			f[i][j]%=mod;
		}
	}
	for(int i=3;i<=n;i++){
		ll cnt=0;
		for(int j=0;j<=a[i];j++){
			cnt+=f[i-1][j];
			cnt%=mod;
		}
		ans+=((C[i]-cnt)%mod+mod)%mod;
		ans%=mod;
	}
	cout<<ans;
	return 0;
}