#include<bits/stdc++.h>
#define int long long
#define pub push_back
#define pii pair<int,int>
#define mkp make_pair
using namespace std;
int n,m,k,addcost[15],cnt,cost[15][11009],fa[11009],ans=1e18;
struct edge{
	int u,v,w;
}d[1100009],d2[1100009];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
struct node{
	int v,w;
};
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
bool cho[20];
void solve(){
	cnt=n-1;
	//cerr<<n<<" "<<cnt<<endl;
	for(int i=1;i<=cnt;i++){
		d2[i]=d[i];
	}
	int now=0,red=0;
	for(int i=1;i<=k;i++){
		if(cho[i]){
			now+=addcost[i];
			red++;
			for(int j=1;j<=n;j++){
				cnt++;
				d2[cnt]=edge{n+red,j,cost[i][j]};
			}
		}
	}
	n+=red;
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(d2+1,d2+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		int fa1=find(d2[i].u);
		int fa2=find(d2[i].v);
		if(fa1!=fa2){
			now+=d2[i].w;
			fa[fa1]=fa2;
		}
	}
	ans=min(ans,now);
	n-=red;
}
void dfs(int x){
	if(x>k){
		solve();
		return;
	}
	cho[x]=1;
	dfs(x+1);
	cho[x]=0;
	dfs(x+1);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(NULL),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>d[i].u>>d[i].v>>d[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>addcost[i];
		for(int j=1;j<=n;j++){
			cin>>cost[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	sort(d+1,d+1+m,cmp);
	for(int i=1;i<=m;i++){
		int fa1=find(d[i].u);
		int fa2=find(d[i].v);
		if(fa1!=fa2){
			cnt++;
			d2[cnt]=d[i];
			fa[fa1]=fa2;
		//	cout<<"add "<<d[i].u<<" "<<d[i].v<<" "<<d[i].w<<"\n";
		}
	}
	for(int i=1;i<=cnt;i++) d[i]=d2[i];
	dfs(1);
	cout<<ans;
	return 0;
}
