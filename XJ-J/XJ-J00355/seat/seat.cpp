#include<bits/stdc++.h>
using namespace std;
int a[11][11];
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int m,n;
	cin>>m>>n;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			cin>>a[n][m];
		}
	}
//	for(int i = 1;i<=n;i++){
//		for(int j = 1;j<=m;j++){
//			if(a[i][j]>a[i][j+1]){
//				a[i][j] = a[1][1];
//			}else{
//				a[i][j+1] = a[1][1];
//			}
//		}
//	}
	
	cout<<a[n-n+1][m-m+1];
	
} 
