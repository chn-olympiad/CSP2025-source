#include<bits/stdc++.h>
using namespace std;

int n,m,k,x;
int a[10005][10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		for(int j=0;j>n;j++){
			a[i][j]=0;
		}
	}
	for(int i=0;i<m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		x+=z;
		a[x][y]=z;
	}
	/*for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){

			}
		}
	}*/
	cout<<x;
	return 0;
}
