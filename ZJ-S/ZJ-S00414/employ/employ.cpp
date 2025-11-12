#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=998244353,N=505;
ll f[2][N][N],cnt[N],fc[N],iv[N];
int n,m,x,pr[N];
char s[N];
void init(){
	fc[0]=iv[0]=iv[1]=1;
	for(int i=2;i<=n;i++) iv[i]=iv[mod%i]*(mod-mod/i)%mod;
	for(int i=1;i<=n;i++) fc[i]=fc[i-1]*i%mod,iv[i]=iv[i-1]*iv[i]%mod;
}
ll C(int n,int m){
	if(n<0||m<0||n<m) return 0;
	return fc[n]*iv[m]%mod*iv[n-m]%mod;
}
ll A(int n,int m){
	if(n<0||m<0||n<m) return 0;
	return fc[n]*iv[n-m]%mod;
}
void tr(ll &x,ll y){
	(x+=y)%=mod;
}
void calc(int i){
	for(int j=0;j<=cnt[0];j++) tr(f[i&1][0][j],A(i,cnt[0]-j));
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=n;i++) scanf("%d",&x),cnt[x]++;
	for(int i=1;i<=n;i++) pr[i]=pr[i-1]+cnt[i];
	init();
	bool fl=1;
	for(int i=1;i<=n;i++){
		if(fl) calc(i-1);
		int u=i&1,v=u^1;fl&=s[i]=='1';
		memset(f[u],0,sizeof(f[u]));
		for(int j=0;j<=n;j++){
			for(int k=0;k<=pr[i-1];k++){
				int rest=i-1-pr[j];
				if(j+1<=n&&k){
					for(int l=0;l<=cnt[j+1];l++)
						tr(f[u][j+1][k-1+l],f[v][j][k]*k%mod*A(rest,cnt[j+1]-l)%mod);
				}
				if(s[i]=='1') tr(f[u][j][k],f[v][j][k]);
				else{
					if(j+1<=n){
						for(int l=0;l<cnt[j+1];l++)
							tr(f[u][j+1][k+l],f[v][j][k]*cnt[j+1]%mod*A(rest,cnt[j+1]-l-1)%mod);
						for(int l=0;l<=cnt[j+1];l++)
							tr(f[u][j+1][k+l],f[v][j][k]*A(rest,cnt[j+1]-l)%mod);
					}
				}
			}
		}
	}
	if(fl) calc(n);
	ll ans=0;
	for(int j=0;j<=n-m;j++){
		int rest=n-pr[j];
		tr(ans,f[n&1][j][0]*fc[rest]%mod);
	}
	printf("%lld\n",ans);
	return 0;
}