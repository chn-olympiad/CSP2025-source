#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1.1e5,inf=2.1e18;

int n,ans=0;
struct Cl{
	int a,b,c;
}f[N];
int best(int a,int b,int c){
	return max(max(a,b),c);
}
int c1,c2,c3;
void dfs(int i,int src){
	if(i==n+1){
		if(c1>n/2||c2>n/2||c3>n/2)return;
		ans=max(ans,src);
		return;
	}
	c1++;
	dfs(i+1,src+f[i].a);
	c1--,c2++;
	dfs(i+1,src+f[i].b);
	c2--,c3++;
	dfs(i+1,src+f[i].c);
	c3--;
	return;
}
void solve(){
	scanf("%lld",&n);
	if(n==2){
		Cl x,y;
		scanf("%lld%lld%lld",&x.a,&x.b,&x.c);
		scanf("%lld%lld%lld",&y.a,&y.b,&y.c);
		ans=max(best(x.a+y.b,x.a+y.c,x.b+y.a),best(x.b+y.c,x.c+y.a,x.c+y.b));
	}else{
		for(int i=1;i<=n;i++)scanf("%lld%lld%lld",&f[i].a,&f[i].b,&f[i].c);
		dfs(1,0);
	}
	printf("%lld\n",ans);
	ans=0,c1=c2=c3=0;
	return;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%lld",&T);
	while(T--)solve();
	return 0;
}
