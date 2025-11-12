#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans,b[20][10010],vis1[1000010],vis2[20][10010];
struct aa{
	int x,y,q;
}a[1000020];
bool cmp(aa x,aa y){
	return x.q<y.q;
}
void dfs(int num){
	for(int i=1;i<=m;i++){
		if(vis1[i]==1)continue;
		vis1[i]=1;
		dfs(num+a[i].q);
		vis1[i]=0;
	}
	for(int i=1;i<=k;i++){
		if(vis2[i][0]==1){
			for(int j=1;j<=n;j++){
				if(vis2[i][j]==1)continue;
		    vis2[i][j]=1;
		    dfs(num+b[i][j]);
		    vis2[i][j]=0;
			}
		}else{
		  vis2[i][0]=1;
		  dfs(num+b[i][0]);
		  vis2[i][0]=0;
		}
	}
	ans=max(ans,num);
}
int main(){
  freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m>>k;
  for(int i=1;i<=m;i++)cin>>a[i].x>>a[i].y>>a[i].q;
  for(int i=1;i<=k;i++){
  	cin>>b[i][0];
  	for(int j=1;j<=n;j++)cin>>b[i][j];
  }
  sort(a+1,a+m+1,cmp);
	dfs(0);
	return 0;
}
