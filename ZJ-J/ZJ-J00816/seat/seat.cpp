#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie();cout.tie();
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int r = 1, rs, x;
	cin >> rs;
	for(int i = 1;i < n * m;i++){
		cin >> x;
		if(x > rs)
			r++;
	}
	int rr = r % n, sr = ceil(r * 1.0 / n);
	if(rr == 0)
		cout << sr << ' ' << n;
	else{
		if(sr % 2 == 0)
			cout << sr << ' ' << n - rr + 1;
		else
			cout << sr << ' ' << rr;
	}
	return 0;
}
