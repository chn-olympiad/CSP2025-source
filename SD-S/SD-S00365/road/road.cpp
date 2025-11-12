#include<iostream>
#include<algorithm>
#include<cstdio>
#define int long long
using namespace std;
struct node{
	int a,b,cc;
}edge[15000011];
int n,m,k;
int fa[30011];
inline int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
int cnt=0;
int len[30011];
inline bool cmp(node q,node w){
	return q.cc<w.cc;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(register int i=1;i<=m;i++){
		cin>>edge[++cnt].a;
		cin>>edge[cnt].b;
		cin>>edge[cnt].cc;
	}
	while(k--){
		int c;
		cin>>c;
		for(register int i=1;i<=n;i++){
			cin>>len[i];
		}
		for(register int i=1;i<=n;i++){
			for(register int j=i+1;j<=n;j++){
				edge[++cnt].a=i;
				edge[cnt].b=j;
				edge[cnt].cc=len[i]+len[j]+c;
			}
		}
	}
	sort(edge+1,edge+cnt+1,cmp);
	for(register int i=1;i<=n;i++) fa[i]=i;
	int ans=0;
	for(register int i=1;i<=cnt;i++){
		int u=find(edge[i].a);
		int v=find(edge[i].b);
		if(u==v) continue;
		fa[u]=v;
		ans+=edge[i].cc;
	}
	cout<<ans<<'\n';
	return 0;
}
