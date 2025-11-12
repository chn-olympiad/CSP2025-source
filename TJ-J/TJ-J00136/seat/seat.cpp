#include <bits/stdc++.h>
using namespace std;
int a[100];
int b[20][20];
bool cmd(int x,int y){
	return x > y;  
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i<=n*m;i++){
		cin >> a[i];
	}
	int r = a[1];
	sort(a+1,a+n*m,cmd);

	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(j==n) {
				if(i%2 == 0) b[i][n] = a[n*(i-1)+1];
				else b[i][n] = a[i*n];
			}
			else if(i%2 == 0) b[i][j] = a[n*(i-1)+(m-j)+1];
			else if(i%2 == 1) b[i][j] = a[i*n-m+j];
		}
	}
	for(int i =1;i <= n;i++){
		for(int j=1;j<=n;j++){
			if(b[i][j] == r) cout << i << " " << j;
		}
	}
}
