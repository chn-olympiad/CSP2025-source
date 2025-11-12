//李承恩 SN-S00343 西安湖滨中学
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+20,M=1e6+10;
int n,m,k,c[12],num,fa[N],z;
ll ans=1e17,sum;
struct node{
	int u,v,w;
}h[M],h2[N*11],h3[11][N*11],a[12][N];
bool cmp(node lcn,node yjx){
	return lcn.w<yjx.w;
}
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void dfs(int x){
	if(x>k){
		for(int i=1;i<=n+k;i++)fa[i]=i;
		ll ret=sum;
		for(int i=1;i<=num;i++){
			int x=find(h2[i].u),y=find(h2[i].v);
			if(x!=y){
				fa[x]=y;
				ret+=h2[i].w;
			}
		}
		ans=min(ans,ret);
		return;
	}
	int num2=num,p1=0,p2=0;
	num=0;
	while(p1<num2||p2<n){
		if(p2!=n&&(p1==num2||a[x][p2+1].w<h2[p1+1].w))h3[x][++num]=a[x][++p2];
		else h3[x][++num]=h2[++p1];
	}
	dfs(x+1);
	swap(h2,h3[x]);
	sum+=c[x];
	z++;
	dfs(x+1);
	z--;
	sum-=c[x];
	swap(h2,h3[x]);
	num=num2;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>h[i].u>>h[i].v>>h[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j].w;
			a[i][j].u=i+n,a[i][j].v=j;
		}
		sort(a[i]+1,a[i]+1+n,cmp);
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(h+1,h+1+m,cmp);
	for(int i=1;i<=m;i++){
		int x=find(h[i].u),y=find(h[i].v);
		if(x!=y){
			fa[x]=y;
			h2[++num]=h[i];
		}
	}
	dfs(1);
	cout<<ans;
	return 0;
}
