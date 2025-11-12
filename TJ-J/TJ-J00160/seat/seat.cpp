#include <iostream>
#include <cstdio>
using namespace std;
int n,m,d;
int a[10000000];
int g[10000000];
int b[1000][1000];
int e;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++){
		cin>>a[i];
	}
	d=a[0];
	e=1;
	for(int i=101;i>=1;i--){
		for(int j=1;j<=n*m;j++){
			if(i<=a[j]){
				g[e]=a[j];
			}
		}
	}
	int f=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				b[i][j]=g[f];
				f++;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				b[i][j]=g[f];
				f++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(d==b[i][j]){
				cout<<i<<j;
				break;
			}
		}
	}
	return 0;
}
