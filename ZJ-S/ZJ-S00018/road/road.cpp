#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
//#define int long long
void init();void Solve();
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int T=1;init();
//	cin>>T;
	while(T--) Solve();
	return 0;
}
void init(){
}
int n,m,k,tot,fa[10005],a[15][10005],mn[15],l[15];
long long ans,cnt;
struct edge{
	int u,v,w;
}q[1000005],t[15][10005];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int find(int x){
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}
struct node{
	int id,num;
};
struct comp{
	bool operator()(node x,node y){
		return x.num>y.num;
	}
};
priority_queue<node,vector<node>,comp>pq;
void Solve(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>q[i].u>>q[i].v>>q[i].w;
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++) cin>>a[i][j];
		for(int j=1;j<=n;j++) if(!mn[i]||a[i][j]<a[i][mn[i]]) mn[i]=j;
		for(int j=1;j<=n;j++) t[i][j]=edge{mn[i],j,a[i][j]};
		sort(t[i]+1,t[i]+1+n,cmp);
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(q+1,q+1+m,cmp);
	for(int i=1;i<=m;i++){
		int x=find(q[i].u),y=find(q[i].v);
		if(x==y) continue;
		t[0][++tot]=q[i];
		fa[x]=y;
	}
	ans=1e18;
	for(int i=0;i<(1<<k);i++){
		cnt=0;l[0]=1;
		while(!pq.empty()) pq.pop();
		pq.push(node{0,t[0][1].w});
		for(int j=1;j<=k;j++)
			if(i&(1<<(j-1))){
				cnt+=a[j][0]+a[j][mn[j]];
				l[j]=1;
				pq.push(node{j,t[j][1].w});
			}
			else l[j]=n+1;
		for(int j=1;j<=n;j++) fa[j]=j;
		for(int j=1,ooo=0;j<=n*k;j++){
			int x=pq.top().id;
			pq.pop();
			int ttt=l[x];
			l[x]++;
			while(l[x]<n&&find(t[x][l[x]].u)==find(t[x][l[x]].v)) l[x]++;
			if(l[x]<n) pq.push(node{x,t[x][l[x]].w});
			int X=find(t[x][ttt].u),Y=find(t[x][ttt].v);
			if(X==Y) continue;
			ooo++;
			fa[X]=Y;
			cnt+=t[x][ttt].w;
			if(ooo==n-1) break;
		}
		ans=min(ans,cnt);
	}
	cout<<ans<<endl;
}

