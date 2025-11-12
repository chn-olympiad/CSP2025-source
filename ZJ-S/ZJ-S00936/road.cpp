#include <bits/stdc++.h>
using namespace std;
long long sum=0;
int n,m,k;
/*struct ro{
	vector<int>aa[1000010];
	int w;
}a[1000010];
*/
struct co{
	int c; 
	int r[1000010];
}b[20];
bool vis[10010];
/*void dfs(long long step){
	
}*/
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,ww;
		cin>>u>>v>>ww;
		/*a[i].aa[u].push_back(v);
		a[i].aa[v].push_back(u);
		a[i].w=ww;*/
		sum+=ww;
	}
	for(int i=1;i<=k;i++){
		cin>>b[i].c;
		for(int j=1;j<=n;j++){
			cin>>b[i].r[j];
		}
	}
	//dfs();
	cout<<sum;
	fclose(stdin);
	fclose(stdout);

	return 0;
}
