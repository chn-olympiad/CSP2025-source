#include <bits/stdc++.h>
using namespace std;
int n,m,k,a[10005],oth[11][10001],g[10001][10001];
int u,v,w,towns,bt;
bool vis[10001][10001],ovis[11][10001],v_twon[10001];
long long sum=1e13;
long long as,df,gh,jk;
void dfs(int x,long long num){
	//cout<<x<<" "<<num<<" "<<towns<<endl;
	if(num>=sum){
		//cout<<endl;
		return ;
	}
	if(towns==n){
		sum=num;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i][x]||v_twon[i]){
			continue;
		}
		vis[i][x]=vis[x][i]=1;
		as=g[i][x];
		for(int j=1;j<=k;j++){
			df=oth[j][i]*ovis[j][i];
			gh=oth[j][x]*ovis[j][x];
			jk=oth[j][0]*ovis[j][0];
			if(as>df+gh+jk){
				as=df+gh+jk;
				bt=j;
			}
		}
		ovis[bt][i]=ovis[bt][x]=ovis[bt][0]=0;
		towns++;
		v_twon[i]=1;
		dfs(i,num+as);
		v_twon[i]=0;
		towns--;
		ovis[bt][i]=ovis[bt][x]=ovis[bt][0]=1;
		vis[i][x]=vis[x][i]=0;
	}
}
int main(){
	freopen("road.in ","r",stdin);
	freopen("road.out ","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			g[i][j]=0x3fffffff;
		}
		vis[i][i]=1;
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			ovis[i][j]=1;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		g[u][v]=g[v][u]=min(g[u][v],w);
	}
	for(int j=1;j<=k;j++){
		for(int i=0;i<=n;i++){
			cin>>oth[j][i];
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<g[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	v_twon[1]=1;
	towns=1;
	dfs(1,0);
	cout<<sum;
	return 0;
}
