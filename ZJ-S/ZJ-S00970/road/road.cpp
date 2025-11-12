#include<bits/stdc++.h>
using namespace std;
vector<int> mp[10005];
vector<int> v[10005];
int cz[15][10005];
long long ans=LONG_LONG_MAX;
bool vis[15];
int n,m,k;
bool zgcs[1005];
void solve(long long sum){
	memset(zgcs,0,sizeof(zgcs));
	bool flag=1;
	zgcs[1]=1;
	while(flag){
		bool ff=1;
		for(int i=1;i<=n;i++){
			if(zgcs[i]==0){
				ff=0;
				break;
			}
		}
		if(ff==1){
			break;
		}
		int minn=INT_MAX,nxtpl;
		for(int i=1;i<=n;i++){
			if(zgcs[i]==0)continue;
			for(int j=0;j<mp[i].size();j++){
				if(zgcs[mp[i][j]]==1)continue;
				if(v[i][j]<minn){
					minn=v[i][j];
					nxtpl=mp[i][j];
				}
			}
		}
		for(int i=1;i<=k;i++){
			if(vis[i]==0)continue;
			for(int j=1;j<=n;j++){
				if(zgcs[j]==1)continue;
				if(cz[i][j]<minn){
					nxtpl=j;
					minn=cz[i][j];
				}
			}
		}
		sum+=minn;
		zgcs[nxtpl]=1;
	}
	ans=min(ans,sum);
}
void dfs(int x,long long cost){
	if(x>k){
		solve(cost);
		return;
	}
	vis[x]=1;
	dfs(x+1,cost+cz[x][0]);
	vis[x]=0;
	dfs(x+1,cost);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		mp[a].push_back(b);
		mp[b].push_back(a);
		v[a].push_back(c);
		v[b].push_back(c);
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			scanf("%d",&cz[i][j]);
		}
	}
	dfs(1,0);
	printf("%lld",ans);
}