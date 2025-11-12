#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[101][101],b[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i]>b[i-1]){
				cout<<a[i][j];
			}else {
				cout<<a[i+1][j-1];
			}
		}
	}
	return 0;
} 
