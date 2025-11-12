#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r");
	freopen("seat.out","w");
	int a[101] = {};
	int c[11][11]={};
	int n,m,b,d=0,e,f;
	cin>>n>>m;
	for(int i=0;i<m*n;i++) {
		cin>>a[i];
		if(i=0){
			b = a[i] ;
		}
	}
	sort(a,a+n*m);
	for(int i=0;i<=m;i++){
		if(i%2==1){
			for(int j=0;j<=n;j++){
				c[i][j] = a[d];
			}
		}
		else{
			for(int j=n;j>=1;j++){
				c[i][j] = a[d];
			}	
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(c[i][j] == b){
				cout<<i<<" "<<j;
			}
		}
	}
	return 0;
}
