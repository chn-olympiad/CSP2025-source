#include<bits/stdc++.h>
using namespace std;

const int N=1e6+5;
long long o[1005][1005];
long long n,m,k,x,y,z,a[20][N],ans,minx=INT_MAX;
int main(){
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		o[x][y]=z;
		o[y][x]=z;
	}for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			//TODO
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(o[i][j]!=0) {
				for(int l=1;l<=k;l++){
					minx=min(minx,min(o[i][j],a[l][i]+a[l][j]+a[l][0]));
				}
				o[i][j]=0;
				o[j][i]=0;
				ans+=minx;
			}	
			
		}
	}
	cout<<ans;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}