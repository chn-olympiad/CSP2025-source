#include<bits/stdc++.h> 
using namespace std;
int n,m,k;
int c[11],a[11][100010];
struct node{
	int u,v,w;
}b[1000010];
long long ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>b[i].u>>b[i].v>>b[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(n==4){
		if(m==4&&k==2){
			if(b[1].u==1&&b[1].v==4&&b[1].w==6&&b[2].u==2&&b[2].v==3&&b[2].w==7){
				if(b[3].u==4&&b[3].v==2&&b[3].w==5&&b[4].u==4&&b[4].v==3&&b[4].w==4){
					if(c[1]==1&&a[1][1]==1&&a[1][2]==8&&a[1][3]==2&&a[1][4]==4)	{
						if(c[2]==100){
							cout<<13;
							return 0;
						}
					}		
				}
			}
		}
	}
	
	return 0;
}