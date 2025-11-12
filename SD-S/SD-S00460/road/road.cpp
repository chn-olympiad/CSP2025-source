#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+10;
int g[N][N],vis[N];int n,m,k;
int ans=1e9+10;
void dfs(int u,int d,int all){
	if(d>=n){
		ans=min(all,ans);
	}
	for(int i=0;i<n;i++){
		if(!vis[i]&&g[u][i]!=0x3f3f3f3f){
			vis[i]=1;
			dfs(i,d+1,all+g[u][i]);


			vis[i]=0;
		}
	}
	return;
}
signed main(){
	freopen("road.in","r",stdin); 
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(g,0x3f,sizeof(g));
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int q,w,e;
		cin>>q>>w>>e;
		g[q-1][w-1]=e;
		g[w-1][q-1]=e;
	}
	for(int i=0;i<k;i++){
		int a;
		cin>>a;
		vector<int> tmp;
		for(int i=0;i<n;i++){
			int tt;
			cin>>tt;
			tmp.push_back(tt);
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				g[i][j]=min(tmp[i]+a+tmp[j],g[i][j]);
				
			}
		}
	}
	for(int i=0;i<n;i++){
		dfs(i,0,0);
	} 
	cout<<ans;
	return 0;
}
