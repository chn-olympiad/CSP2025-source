#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[110];
int now;
int ansx, ansy;

bool cmp(int a, int b){
	return a > b;
}

void dfs(int x, int y, int op, int cnt){
	// cout << x << ' ' << y << ' ' << op << ' ' << cnt << endl;
	// if (x == n && y == m) return ;
	if (a[cnt] == now){
		ansx = x;
		ansy = y;
		return ;
	}
	if (op == 1){
		// cout << "1 ";
		if (x == n){
			dfs(x, y+1, 2, cnt+1);
		} else {
			dfs(x+1, y, 1, cnt+1);
		}
	} else if (op == 2){
		// cout << "2 ";
		if (x == 1){
			dfs(x, y+1, 1, cnt+1);
		} else {
			dfs(x-1, y, 2, cnt+1);
		}
	}
}
int main (){
	
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++){
		cin >> a[i];
	}
	now = a[1];
	// cout << now << "\n";
	sort(a+1, a+1+n * m, cmp);
	/*for (int i = 1; i <= n * m; i++){
		cout << a[i] << ' ';
	}*/
	dfs(1, 1, 1, 1);
	cout << ansy << ' ' << ansx;
	
	return 0;
}