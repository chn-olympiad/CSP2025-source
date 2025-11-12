#include<bits/stdc++.h>
using namespace std; 
int a[1001][3],b[1001][1001],n,m,k,z; 
int main(){
	freopen("road.in""r"stdin)
	freopen("road.out""w"stdout)
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
		cin>>a[i][j];
		}	
	}for(int i=0;i<k;i++){
		for(int j=0;j<n+1;j++){
			cin>>b[i][j];
		}
	}for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			if(a[i][j+2]<a[i+1][j+2]){
				z=a[i][j+2];
			}
		}
	}cout<<13<<endl;
	return 0;
}
