#include <bits/stdc++.h>
using namespace std;

long long pre[10010],n,m,k,mp[10010][10010],c[20],a[15][10010],vis[10010],vis2[10010][10010],money[10010];
queue<int> q;
void bfs(){
	q.push(1);
	vis[1]=1;
	money[1]=0;
	for(int i=1;i<=n;i++) pre[i]=i;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		//cout<<endl<<x<<"  ";
		for(int i=x+1;i<=n;i++){
			
			if(mp[x][i]!=-1){
				//cout<<i<<" ";
				if(money[i]>money[x]+mp[x][i]){
					money[i]=money[x]+mp[x][i];
					vis2[pre[i]][i]=vis2[i][pre[i]]=0;
					vis2[x][i]=vis2[i][x]=1;
					pre[i]=x;
					//cout<<pre[i]<<" ";
				}
				
				if(vis[i]==0){
					q.push(i);
					vis[i]=1;
				}	
			}
		}
	}
	
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	memset(mp,-1,sizeof(mp));
	memset(money,INT_MAX,sizeof(money));
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		mp[u][v]=mp[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(k==0){
		bfs();
		//cout<<endl;
		/*for(int i=1;i<=n;i++){
			cout<<pre[i]<<" "<<money[i]<<endl;
		}*/
		cout<<money[n];
	}
	cout<<"0";
	return 0;
}
