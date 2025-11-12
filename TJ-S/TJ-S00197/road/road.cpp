#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
long long n,m,k,vis[10005],cnt=0,a[1005][1005],e[1005][1005],ans;
struct node{
	int x;
	long long w;
}tmp;
bool operator < (node x,node y){
	return x.w>y.w;
}
priority_queue<node>q;
void dfs(int x){
	if(cnt==n)return;
	for(int i=1;i<=n;i++){
		if(vis[i]==0&&e[x][i]<=1e14){
			tmp.x=i,tmp.w=e[x][i];
			q.push(tmp);
		}
	}
	while(true){
		int x=q.top().x;
		long long w=q.top().w;
		q.pop();
		if(vis[x]==0){
			vis[x]=1;
			cnt++;
			ans+=w;
			dfs(x);
			break;
		}
		if(cnt==n)break;
	}
	if(cnt==n)return;
}
int main(){
	freopen("road.in","r",stdin); 
	freopen("road.out","w",stdout);  
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			e[i][j]=1e14;
		}
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[u][v]=w;
		e[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
		for(int j=1;j<=n;j++){
			for(int k1=1;k1<=n;k1++){
				if(j!=k1){
					e[j][k1]=min(e[j][k1],a[i][k1]+a[i][j]);
					e[k1][j]=min(e[j][k1],a[i][k1]+a[i][j]);
				}
			}
		}
	}
	vis[1]=0;
	cnt=1;
	dfs(1);
	cout<<ans<<endl;
	return 0; 
}
