// Goodbye Cifera

// Expect: 100pts

#include <bits/stdc++.h>

#define ll long long

using namespace std; 

#define pii pair<int, int>
#define x first
#define y second

int n, m, num, cnt, x, y, flg = 1;   

signed main()
{
	freopen("seat.in", "r", stdin); 
	freopen("seat.out", "w", stdout); 
	
	cin.tie(nullptr) -> sync_with_stdio(false); 

	cin >> n >> m; 
	for(int i = 1, x; i <= n * m; i ++) {
		cin >> x; 
		if(i == 1) num = x;
		else if(num < x) cnt ++; 
	}

	x = y = 1; 

	while(cnt --) 
		if(x == n && flg == 1) flg = -1, y ++; 
		else if(x == 1 && flg == -1) flg = 1, y ++;
		else x += flg;

	cout << y << ' ' << x << '\n';

	return 0; 
}