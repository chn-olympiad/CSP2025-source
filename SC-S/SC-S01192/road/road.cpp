#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=10005;
const int M=1000005;
int n,m,k,x,y,z,ans=0x7fffffff;
int a[1005][1005],usd[N];
int b[10005][15];
void dfs(int i,int k,int sum){
//	cout<<i<<endl;
	if(k==n){
//		cout<<1<<" ";
		ans=min(ans,sum);
		return;
	}
	for(int j=1;j<=n;j++){
		if(a[i][j]!=0&&i!=j){
			if(usd[j]==0){
				usd[j]=1;
				dfs(j,k+1,sum+a[i][j]);
				usd[j]=0;
			}
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>x>>y>>z;
		a[x][y]=a[y][x]=z;
	}
	for(int i=1;i<=k;i++){
		cin>>b[0][i];
		for(int j=1;j<=n;j++){
			cin>>b[j][i];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int o=1;o<=k;o++){
				if(a[i][j]==0)a[i][j]=a[j][i]=b[0][o]+b[i][o]+b[j][o];
				else{
					a[i][j]=a[j][i]=min(a[i][j],b[0][o]+b[i][o]+b[j][o]);
				}
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<a[i][j]<<" ";
//		}cout<<endl;
//	}
	usd[1]=1;
	dfs(1,1,0);
	cout<<ans;
	return 0;
}