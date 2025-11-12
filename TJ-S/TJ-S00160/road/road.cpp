#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
struct node{
	int u,v,next,val;
	friend bool operator<(const node a,const node b){
		return a.val<b.val;
	}
}edge[2*N];
int n,m,k;
int head[N],cnt;
bool vis[N];
int val[N],c[N];
void add(int x,int y,int val){
	edge[++cnt].v=y;
	edge[cnt].u=x;
	edge[cnt].next=head[x];
	edge[cnt].val=val;
	head[x]=cnt;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(head,-1,sizeof(head));
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,val;
		cin>>u>>v>>val;
		add(u,v,val);
		add(v,u,val);
	}
	for(int i=1;i<=k;i++){
		int x;
		cin>>c[n+i];
		for(int j=1;j<=n;j++){
			cin>>x;
			add(n+i,j,x+c[n+i]);
			add(j,n+i,x+c[n+i]);
		}
	}
	sort(edge,edge+cnt);
	int ans=0;
	for(int i=1;i<=cnt;i++){
		if(!vis[edge[i].v]&&edge[i].u<=n&&edge[i].v<=n){
			val[edge[i].v]=edge[i].val;
			vis[edge[i].v]=true;
			ans+=edge[i].val;
		}else if(edge[i].u>n||edge[i].v>n){
			if(vis[edge[i].u]&&edge[i].v<=n){
				if(val[edge[i].v]>edge[i].val-c[edge[i].u]){
					ans-=val[edge[i].v];
					ans+=(edge[i].val-c[edge[i].u]);
				}else if(!val[edge[i].u]){
					if(val[edge[i].v]>edge[i].val){
						ans-=val[edge[i].v];
						ans+=edge[i].val;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0; 
}
