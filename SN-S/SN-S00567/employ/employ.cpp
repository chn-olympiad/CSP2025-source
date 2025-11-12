#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505,Q=18,m=998244353;
int n,k,a[N],c[N],s[1<<Q];
ll ans,f[1<<Q][Q];
void ad(ll &x,ll y){x=(x+y)%m;}
void sol(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		char ch;
		cin>>ch;
		a[i]=ch-'0';
	}
	for(int i=0;i<n;i++) scanf("%d",&c[i]);
	f[0][0]=1;
	for(int i=0;i<(1<<n);i++){
		if(i) s[i]=s[i-(i&-i)]+1;
		for(int j=0;j<=s[i];j++) if(f[i][j]){
			for(int p=0;p<n;p++) if(!((i>>p)&1)){
				if(s[i]-j>=c[p]) ad(f[i|(1<<p)][j],f[i][j]);
				else ad(f[i|(1<<p)][j+a[s[i]]],f[i][j]);
			}
		}
	}
	for(int i=k;i<=n;i++) ad(ans,f[(1<<n)-1][i]);
	printf("%lld\n",ans);
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
//	ii();
//	int TT;for(scanf("%d",&TT);TT--;)
	sol();
	return 0;
}
