#include<bits/stdc++.h>
using namespace std;
int n, m, a[105], b[105], seat[15][15], c, r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1; i<=n*m; i++){
		cin >> a[i];
	}
	for(int i=1; i<=n*m; i++){
		b[i] = a[i];                   
	}
	for(int i=1; i<n*m; i++){
		for(int j=1; j<n*m; j++){
			int a = 0;
			if(b[i+1] > b[i]){
				a = b[i];
				b[i] = b[i+1];
				b[i+1] = a;
			}
		}
	}
	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){
			if(i % 2 == 1) seat[i][j] = b[1+(i-1)*n+j-1];
			else if(i % 2 == 0) seat[i][j] = b[2*n-j+1];
		}
	}
	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){
			if(seat[i][j] == a[1]){
				c = i;
				r = j;
				cout << c << ' ' << r;
			}
		}
	}
	return 0;	
}
