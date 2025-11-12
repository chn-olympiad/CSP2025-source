#include<bits/stdc++.h>
using namespace std;
int n,m,k,q;
int x,y,z,o,p;
int b[10010][10010];
int a[10010][10010];
int c;
bool lk[10010][10010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		if(lk[x][y]==1){
			if(z<a[x][y]){
				a[x][y]=z;
			}
		}
		else{
			lk[x][y]=1;
			a[x][y]=z;
		}
		
		for(int k=1;k<=n;k++){
			if(lk[y][k]==1){
				if(lk[x][k]==1){
					if(a[x][y]+a[y][k]<a[x][k]){
						a[x][k]=a[x][y]+a[y][k];
					}
				}
				else{
					lk[x][k]=1;
					a[x][k]=a[x][y]+a[y][k];
				}
				lk[x][k]=1;
			}
		}
	}
	q+=a[1][n]+a[n][1];
	for(int i=1;i<=k;i++){
		for(int h=2;h<=n+1;h++){
			cin>>b[i][h];
		}
		}
		for(int v=1;v<=k;v++){	
			for(int i=1;i<=n;i++){
				for(int l=1;l<=n;l++){
				
					if(b[v][i]+b[v][l]<a[i][v]){
						c=q-a[i][l]+b[v][i]+b[v][l];
						}
					}
				
			}
			
			if(c+b[v][1]<q)	q=c+b[v][1];
		}		
	cout<<q;
	return 0;
	
}
