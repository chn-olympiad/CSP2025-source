#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int maxn=5005,maxm=5005;
const int mod=998244353;
const LL inf=1e18+1;
void read(int& x){
	char c;
	bool f=0;
	while((c=getchar())<48) f|=(c==45);
	x=c-48;
	while((c=getchar())>47) x=x*10+c-48;
	x=(f ? -x : x);
}
int a[maxn];
LL f[maxn];
int n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1);
	int s=a[n];
	LL ans=0;
	memset(f,0xc0,sizeof(f));
	f[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			if(f[j]<0) continue;
			ans=(ans+f[j])%mod;
		}
		ans=(ans+mod-(i-1))%mod;
		for(int j=s;j>=a[i];j--){
			if(f[j-a[i]]<0) continue;
			if(f[j]<0) f[j]=f[j-a[i]];
			else f[j]+=f[j-a[i]],f[j]%=mod;
		}
	}
	LL ansi=1;
	for(int i=1;i<=n;i++) ansi=ansi*2%mod;
	ansi=(ansi+1ll*10*mod-1-1ll*n*(n-1)/2%mod-n-ans)%mod;
	printf("%lld",ansi);
	return 0;
}

