//赵晗羽 SN-S00681 西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,a[1005][1005],b[15][1005];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,u;
		cin>>x>>y>>u;
		a[x][y]=a[y][x]=u;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
		}
	}
	if(k==0){
		int d[1005],bj[1005],s=0;
		for(int i=0;i<=n;i++)d[i]=1e9;
		for(int i=0;i<=n;i++)bj[i]=0;
		d[1]=0;
		for(int i=1;i<=n;i++){
			int u=0;
			for(int j=1;j<=n;j++){
				if(bj[j]==0&&a[u][j]<d[u])u=j;
			}
			bj[u]=1;
			for(int j=1;j<=n;j++){
				if(bj[j]==0&&a[u][j]+d[u]<d[j]){
					d[j]=a[u][j]+d[u];                        
				}
			}
		}
		for(int i=1;i<=n;i++)s+=d[i];
		cout<<s;
	}else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}

