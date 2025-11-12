#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=10000 + 10; 
int n,m,k;
int mat[N][N];
int fix[N][N],p[N];
int a,b,c;
long long ans=1e18;
int mk[N];

void  dfs(int x,int cnt,int num){
	mk[x]=1;
	if(num==(n-1)){
		if(ans>cnt)ans=cnt; 
		return;
	}
	for(int i=1;i<=n;i++){
		if(i!=x&&mk[i]==0){
			mk[i]=1;
			dfs(i,cnt+mat[x][i],(num+1));
			mk[i]=0;
		}
	}
	mk[x]=0;
	
	return;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c;
		mat[a][b]=c;
		mat[b][a]=c;
	}
	
	for(int i=1;i<=k;i++){
		cin>>p[i];
		for(int j=1;j<=n;j++){
			cin>>fix[i][j];
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			for(int l=j+1;l<=n;l++){
				if(mat[j][l]!=0){
					mat[j][l]=min(mat[j][l],fix[i][j]+fix[i][l]+p[i]);
					mat[l][j]=min(mat[l][j],fix[i][j]+fix[i][l]+p[i]);
				}
				else{
					mat[j][l]=fix[i][j]+fix[i][l]+p[i];
					mat[l][j]=fix[i][j]+fix[i][l]+p[i];
				}
			}
		}
	}
	
	dfs(1,0,0);
	cout<<ans;
	
	return 0;
}
