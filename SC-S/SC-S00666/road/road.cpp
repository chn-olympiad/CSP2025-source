#include<bits/stdc++.h>
using namespace std;
long long int n,m,k,a[1005][1005],b[1005],x,y,z,ans,o,p,c[1005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		if(a[x][y]!=0){
			a[x][y]=a[y][x]=min(a[x][y],z);
		}else{
			a[x][y]=a[y][x]=z;
		}
	}
	for(int i=1;i<=k;i++){
		cin>>x;
		for(int j=1;j<=n;j++){
			cin>>c[i];
		}
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(a[x][y]==0){
					a[x][y]=a[y][x]=c[x]+c[y];
				}else{
					a[x][y]=a[y][x]=min(a[x][y],(c[x]+c[y]));
				}
			}
		}
	}
	b[1]=99999999;
	for(int i=2;i<=n;i++){
		b[i]=99999999;
		for(int j=1;j<i;j++){
			b[j]=min(b[j],a[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		ans+=b[i];
	}
	cout<<ans;
	return 0;
} 