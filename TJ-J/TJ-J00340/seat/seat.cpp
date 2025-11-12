#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int R;
	cin >> R;
	int a[n*m], cnt = 1;
	for(int i = 1; i < n * m; i++){
		int temp;
		cin >> temp;
		if(temp > R) cnt++;
		a[i] = temp;
	}
	
	int rn, rm;
	if(cnt == n) rm = cnt / n;
	else rm = cnt / n + 1;
	
	if(cnt % n == 0){
		if(rm % 2 != 0) rn = n;
		else rn = 1;
	} else{
		if(rm % 2 != 0) rn = cnt % n;
		else rn = n - cnt % n + 1;
	}
	
	cout << rm << " " << rn;
	return 0;
}
