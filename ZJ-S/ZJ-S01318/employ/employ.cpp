#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,q[505],c[505],len,last=-1,f[505],op,sum,ans,tot;char s[505];bool v[105];
inline bool cmp(ll x,ll y){return x>y;}
inline void dfs(ll x,ll y){
	if(x==n+1){
		if(y>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(v[i]==false){
			v[i]=true;
			if(q[x]&&c[i]>x-y-1){dfs(x+1,y+1);}
			else{dfs(x+1,y);}
			v[i]=false;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	scanf("%s",&s);len=strlen(s);
	for(int i=0;i<len;i++){
		if(s[i]=='1'){q[i+1]=1;tot++;}
		else{q[i+1]=0;}
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&c[i]);
		if(c[i]==0){sum++;}
	}
	if(tot<m||n-sum<m){printf("%lld",0);return 0;}
	if(tot==n){
		for(int i=1;i<=n;i++){f[i]=f[i-1]*i%998244353;}
		printf("%lld",f[n]);return 0;
	}
	dfs(1,0);printf("%lld",ans);
	return 0;
}
