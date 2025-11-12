#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
long long MIN_1=0x3f3f3f3f;
long long n,m,k,dt[N][N],x1,y1,fy,jz,fy1[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<n+1;i++){
		for(int j=0;j<n+1;j++){
			dt[i][j]=0x3f3f3f3f;
			if(i==j) dt[i][j]=0;
		}
	}
	for(int i=0;i<m;i++){
		cin>>x1>>y1>>fy;
		dt[x1][y1]=min(dt[x1][y1],fy);
		dt[y1][x1]=min(dt[y1][x1],fy);
	}
	for(int i=0;i<k;i++){
		cin>>jz;
		for(int j=0;j<n;j++){
			cin>>fy1[j];
		}
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				dt[j][k]=min(dt[j][k],fy1[j]+fy1[k]+jz);
				dt[k][j]=min(dt[k][j],fy1[j]+fy1[k]+jz);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dt[j][k]=min(dt[j][k],dt[j][i]+dt[i][k]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		long long he=0;
		for(int j=1;j<=n;j++){
			he+=dt[i][j];
		}
		MIN_1=min(MIN_1,he);	
	}
	cout<<MIN_1<<" ";
	return 0;
}