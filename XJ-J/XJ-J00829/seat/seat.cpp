#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat .in","r",stdin);
	freopen("seat .out","w",stdout);
	int n,m,c;
	cin>>n>>m;
	long long a[11][11];
	long long a2[11][11];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	a[0][0]=c;
	for(int x=100;x>=0;x--){
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
			 if (a[i][j]==x){
					a[i][j]=a2[m*n-i+1][m*n-j+1];
					a[i][j]=0;
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a2[i][j]==c)
				cout<<i<<" "<<j;
		}
	}
	return 0;
}
