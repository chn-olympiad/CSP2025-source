#include<bits/stdc++.h>
#define int long long
using namespace std;
struct edge{
	int u,v;
}e[1000006];
int n,m,k,cnt=0,c[10005],s[10005],mp[10005][10005],fa[10005],sum=1e18,ans=0,mres=0;
vector<int>tree[10005];
int find(int x){
	return fa[x]=(fa[x]==x?x:find(fa[x]));
}
bool cmp(edge x,edge y){
	return mp[x.u][x.v]<mp[y.u][y.v];
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	srand(time(NULL));
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		e[++cnt].u=u;e[cnt].v=v;mp[u][v]=mp[v][u]=w;
		mres+=w;
	}
	for(int i=1;i<=k;i++){
		int res=0;
		scanf("%lld",&c[i]);
		res+=c[i];
		for(int j=1;j<=n;j++){
			scanf("%lld",&s[j]);
			res+=s[i];
		}
		sum=min(sum,res);
	}
	if(k==0){
		sort(e+1,e+1+cnt,cmp);
		for(int i=1;i<=cnt;i++){
			int x=find(e[i].u),y=find(e[i].v);
			if(x==y)continue;
			fa[x]=y;
			sum++;
			ans+=mp[e[i].u][e[i].v];
			if(sum==n-1)break;
		}
		printf("%lld",ans);
		return 0;
	}
	if(sum==0){
		cout<<0<<endl;
		return 0;
	}
	printf("%lld",mres);
	return 0;
}

