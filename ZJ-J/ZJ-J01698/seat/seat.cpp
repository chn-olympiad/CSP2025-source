#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 200;
int a[N] , f[N][N] , ans[N][N] , x[N] , y[N];
bool cmp(int a , int b){
	return a > b;
}
int main(){
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	int n , m;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i ++)
		cin >> a[i];
	int r = a[1];
	sort(a + 1 , a + n * m + 1 , cmp);
	f[1][1] = 1;
	for(int i = 1; i <= m; i ++){
		if(i % 2) 
			for(int j = 1; j <= n; j ++){
				if(j == 1 && i != 1) f[i][j] = f[i - 1][j] + 1;
				else f[i][j] = f[i][j - 1] + 1;
				x[a[f[i][j]]] = i;
				y[a[f[i][j]]] = j;
		}
		else 
			for(int j = n; j >= 1; j --){
				if(j == n) f[i][j] = f[i - 1][j] + 1;
				else f[i][j] = f[i][j + 1] + 1;
				x[a[f[i][j]]] = i;
				y[a[f[i][j]]] = j;
		}	
	}
	cout << x[r] << " " << y[r];
	return 0;
}
