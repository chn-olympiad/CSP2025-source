#include <bits/stdc++.h>
using namespace std;
int n, m, a, cnt = 1, c, r, w; 

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m >> a;
	for (int i = 1; i < n * m; i ++){
		cin >> w;
		if (a < w) cnt ++; 
	}
	c = (cnt - 1) / n + 1;
	int s = cnt - (c - 1) * n;
	if (c % 2){
		r = s;
	}else{
		r = n - s + 1;
	}
	cout << c << " " << r;
	return 0;
}
