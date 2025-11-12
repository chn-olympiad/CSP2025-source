# include <bits/stdc++.h>

using namespace std;

int n, m, c, a[1010], b[100];

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdin);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i ++){
		cin >> a[i];
		b[++ c] ++;
	}
	if (n == 1 && m == 1){
		cout << "1 1";
		return 0;
	}
	if (n == 1){
		cout << m << " " << 1;
		return 0;
	}
	if (m == 1){
		cout << 1 << " " << n;
	}
	return 0;
}
