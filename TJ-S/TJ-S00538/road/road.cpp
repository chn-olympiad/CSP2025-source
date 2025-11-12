#include<bits/stdc++.h>
using namespace std;
int n,m,k,cnt=0;
int a[10005][10005];
int vis[10005];
void dfs(int x){
	int minn=1e9;
	vis[x]=1;
	int j=0;
	for(int i=1;i<=m;i++){
		if(a[x][i]&&!vis[i]){
			minn=a[x][i];
			j=i;
			cnt+=a[x][j];
			dfs(j);
		}
	}
	if(j==0) return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","r",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		a[x][y]=z;
		a[y][x]=z;
	}
	int minnx=1e9;
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		cnt=0;
		dfs(i);
		minnx=min(minnx,cnt);
		cout<<minnx<<endl<<endl;
	}
	cout<<minnx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
