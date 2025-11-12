#include <bits/stdc++.h>
using namespace std;
int main(){
 	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int a[n][m];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	int maxn=INT_MIN;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==maxn){
				maxn=a[i][j];
			}
			if(a[i][j]==a[m][n]){
				a[i][j]=a[i+1][j+1];
			}
			if(i>=2&&j==1){
				a[i][j]=a[i+1][j];
			}
			if(i!=n&&i!=1&&j!=1&&j!=m){
				a[i][j]=a[i][j+1];
			}
		}
		cout<<a[i][j];
	}
	return 0;
}

