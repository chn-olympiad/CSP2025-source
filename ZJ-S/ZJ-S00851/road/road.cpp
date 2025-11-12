#include<bits/stdc++.h>
using namespace std;
const int M=1e6+10;
const int N=1e3+10;
int n,m,k;
int q[N][N];
int a[N];
bool f[N];
int ans=0;
void dfs(int now,int w){
	f[now]=true;
	bool flag=true;
	if(w>ans&&ans!=0) return;
	for(int i=1;i<=n;i++){
		if(!f[i]){
			flag=false;
			dfs(i,w+q[now][i]);
		}
	}
	if(flag){
		ans=min(ans,w);
	}
	return ;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int x,y,g;
		scanf("%d%d%d",&x,&y,&g);
		q[x][y]=g;
		q[y][x]=g;
	}for(int i=1;i<=k;i++){
		int c;
		scanf("%d",&c);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i]);
		}
		for(int j=1;j<n;j++){
			for(int jj=j+1;jj<=n;jj++){
				if(q[j][jj]==0){
					q[j][jj]=a[j]+a[jj]+c;
				}else{
					q[j][jj]=min(a[j]+a[jj]+c,q[j][jj]);
				}
			}
		}
	}
	for(int i=1;i<=n;i++) q[i][i]=0;
	dfs(1,0);
	cout<<ans;
	return 0;
}