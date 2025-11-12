#include<bits/stdc++.h>
using namespace std;
#define int long long
 int n,m,k,mn=1e18;
 int a[20];
 int fa[10030],sz[10030];
 bool vs[20];
 vector<pair<int,pair<int,int> > >ar1,ar;
void init(int r){
	for(int i=1;i<=r;i++){
		fa[i]=i;
		sz[i]=1;
	}
}
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void hb(int u,int v){
	int x=find(u),y=find(v);
	if(sz[x]<sz[y])swap(x,y);
	sz[x]+=sz[y];
	fa[y]=x;
}
int krkr(int n1){
	int as=0,as1=0;
	init(n+k);
	for(auto l:ar){
		int w=l.first,u=l.second.first,x=find(u),v=l.second.second,y=find(v);
		if(x==y||u>n&&!vs[u-n])continue;
		hb(x,y);
		as+=w;
		as1++;
		if(as1==n1-1)break;
	}
	return as;
}
void dfs(int p,int s,int s1){
	if(s>=mn)return ;
	if(p>k){
		mn=min(mn,krkr(s1)+s);
		return ;
	}
	dfs(p+1,s,s1);
	vs[p]=1;
	dfs(p+1,s+a[p],s1+1);
	vs[p]=0;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		ar1.push_back({w,{u,v}});
	}
	sort(ar1.begin(),ar1.end());
	init(n);
	for(auto l:ar1){
		int w=l.first,u=l.second.first,x=find(u),v=l.second.second,y=find(v);
		if(x==y)continue;
		hb(x,y);
		ar.push_back({w,{u,v}});
	}
	for(int i=1;i<=k;i++){
		cin>>a[i];
		for(int j=1,x;j<=n;j++){
			cin>>x;
			ar.push_back({x,{n+i,j}});
		}
	}
	sort(ar.begin(),ar.end());
	dfs(1,0,n);
	cout<<mn;
	return 0;
}
