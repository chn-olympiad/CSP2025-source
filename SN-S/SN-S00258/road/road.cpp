#include<bits/stdc++.h>
#define int long long
using namespace std;
//MST外的边一定没有贡献 
int n,m,k;
struct node{
	int u,v,pw;
}edge[1000101];
bool cmp(node a,node b){
	return a.pw<b.pw;
}
int fa[10101];
int cst[21],pww[11][10101];
int fnd(int x){
	if(fa[x]==x)
		return x;
	fa[x]=fnd(fa[x]);
	return fa[x];
}
int mn=0;
node edge1[20001],edge2[200101];
int cnt=0,cntt=0;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
		cin>>edge[i].u>>edge[i].v>>edge[i].pw;
	for(int i=1;i<=k;i++){
		cin>>cst[i];
		for(int j=1;j<=n;j++)
			cin>>pww[i][j];
	}
	sort(edge+1,edge+1+m,cmp);
	for(int i=1;i<=m;i++){
		int x=fnd(edge[i].u),y=fnd(edge[i].v);
		if(x!=y){
			fa[x]=y;
			cnt++;
			edge1[cnt].pw=edge[i].pw,edge1[cnt].u=edge[i].u,edge1[cnt].v=edge[i].v;
			mn+=edge[i].pw;
		}
	}
	if(k==0){
		cout<<mn;
		return 0;
	}
	for(int i=1;i<(1<<k);i++){//状压 
		cntt=0;
		for(int j=1;j<=n+k;j++)
			fa[j]=j;
		for(int j=1;j<=cnt;j++)
			edge2[j]=edge1[j],cntt++;
		int ans=0;
		for(int j=1;j<=k;j++){
			if((i>>(j-1))&1){
				ans+=cst[j];
				for(int l=1;l<=n;l++)
					cntt++,edge2[cntt].u=l,edge2[cntt].v=n+j,edge2[cntt].pw=pww[j][l];
			}
		}
		sort(edge2+1,edge2+1+cntt,cmp);
		for(int j=1;j<=cntt;j++){
			int x=fnd(edge2[j].u),y=fnd(edge2[j].v);
			if(x!=y){
				fa[x]=y;
				ans+=edge2[j].pw;
			}
		}
		mn=min(mn,ans);
	}
	cout<<mn;
	return 0;
}
