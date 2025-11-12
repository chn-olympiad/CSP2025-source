#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,ans;
struct node{
	ll a,b,c;
}peo[100005];
bool jini(node a,node b){
	return a.a>=b.a;
}
void dfs(int xus,ll sum,ll sa,ll sb,ll sc){
	if(xus>n){
		ans=max(ans,sum);
		return ;
	}
	if(sa+1<=n/2) dfs(xus+1,sum+peo[xus].a,sa+1,sb,sc);
	if(sb+1<=n/2) dfs(xus+1,sum+peo[xus].b,sa,sb+1,sc);
	if(sc+1<=n/2) dfs(xus+1,sum+peo[xus].c,sa,sb,sc+1);
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		ans=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&peo[i].a,&peo[i].b,&peo[i].c);
		}
		if(n<=30){
			dfs(1,0,0,0,0);
			printf("%lld\n",ans);
		}
		else{
			sort(peo+1,peo+n+1,jini);
			for(int i=1;i<=n/2;i++) ans+=peo[i].a;
			printf("%lld\n",ans);
		}
	}
	return 0;
}