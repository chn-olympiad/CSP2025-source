#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
vector<long long> a[10005];
long long kk[15][10005];
long long ans=1000000000;
int vis[10005];
map<pair<long long,long long>,long long> mp;
void dfs(int x,int cnt,long long sum){
	if(cnt==n){
		ans=min(ans,sum);
		return ;
	}
	for(int i=0;i<a[x].size();i++){
		if(vis[a[x][i]]==0){
			vis[a[x][i]]=1;
			dfs(a[x][i],cnt+1,sum+mp[make_pair(x,a[x][i])]);
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	long long u,v,w;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			mp[make_pair(i,j)]=1000000000;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		a[u].push_back(v);
		a[v].push_back(u);
		mp[make_pair(u,v)]=w;
		mp[make_pair(v,u)]=w;
	}
	int cnt=0;
	for(int i=1;i<=k;i++){
		int flag=0;
		for(int j=0;j<=n;j++){
			cin>>kk[i][j];
			if(kk[i][0]==0){
				flag=1;
				cnt++;
			}
			if(flag==1&&j!=0){
				for(int x=1;x<=n;x++){
					for(int y=1;y<=n;y++){
						mp[make_pair(x,y)]=min(mp[make_pair(x,y)],kk[i][x]+kk[i][y]);
						mp[make_pair(y,x)]=min(mp[make_pair(y,x)],kk[i][x]+kk[i][y]);
						
					}
				}
			}
		}
	}
	vis[1]=1;
	dfs(1,1,0);
	cout<<ans;
	return 0;
}
