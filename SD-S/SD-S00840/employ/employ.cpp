#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	int s = 0;char ch = getchar();
	while(!isdigit(ch))ch = getchar();
	while(isdigit(ch))s = (s<<1)+(s<<3)+ch-'0',ch = getchar();
	return s;
}
const int N = 505;
const ll md = 998244353;
ll fp(ll x,int p = md-2){
	ll res = 1;
	while(p){
		if(p&1)res = res*x%md;
		x = x*x%md;
		p>>=1;
	}
	return res;
}
inline void adv(ll &x,ll v){(x+=v)%=md;}
char st[N];
int n,m,c[N],s[N];
ll f[N][N],g[N][N],jc[N][2] = {1};
inline ll A(int x,int y){
	if(0<=y&&y<=x)return jc[x][0]*jc[x-y][1]%md;
	return 0;
}
int main(){
		freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	for(int i = 1;i<=500;i++){
		jc[i][0] = jc[i-1][0]*i%md;
		jc[i][1] = jc[i-1][1]*fp(i)%md;
	}
	n = read();m = read();
	scanf("%s",st+1);
	for(int i = 1;i<=n;i++)c[read()]++;
	for(int i = 1;i<=n;i++)s[i] = s[i-1]+c[i];
	g[0][0] = 1;
	for(int i = 1;i<=n;i++){
		memset(f,0,sizeof(f));
		for(int mj = 1,j,tk;mj<=i;mj++){
			j = mj-1;
			for(int k = 0;k<s[j-1];k++){
				for(int t = 0;t<=c[j];t++){
					tk = c[j]-t+k-1;
					if(tk<0)continue;
					adv(f[mj][tk],k*A(i-(j?s[j-1]:0)+j-1,t)*g[j][k]);
					adv(f[mj][tk],t*A(i-(j?s[j-1]:0)+j-1,t-1)*g[j][k]);
					if(st[i]=='0')adv(f[mj][tk+1],A(i-(j?s[j-1]:0)+j-1,t));
				}
			}
		}
		if(st[i]=='0')memcpy(g,f,sizeof(f));
		else for(int j = 0;j<=n;j++)
			for(int k = 0;k<=n;k++)adv(g[j][k],f[j][k]);
	}
	ll ans = 0;
	for(int i = 1;i<=n-m;i++)adv(ans,g[i][0]*jc[s[n]-s[i-1]][0]);
	adv(ans,md);
	printf("%lld\n",ans);
	return 0;
}

