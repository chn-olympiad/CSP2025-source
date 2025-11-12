#include<bits/stdc++.h>
using namespace std;
const int N = 1e2 + 10;
int a[N];
bool cmp(int x, int y) {
	return x > y;
}
int mp[N][N];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int nn, mm;
	cin >> nn >> mm;
	int n = nn * mm;
	int p;
	for(int i = 1; i <= n; i++) cin >> a[i];
	p = a[1];
	bool f = 1;
	sort(a + 1, a + 1 + n, cmp);
	int x = 1, y = 1;
	int d = 1;
	int cnt = 0;
	while(x <= nn && y <= mm) {
		if(f) cnt++;
		if(a[cnt] == p) {
			cout << y << " " << x << endl;
			break;
		}
		if(d == 1) x++;
		else if(d == 3) x--;
		cnt++;
		if(a[cnt] == p) {
			cout << y << " " << x << endl;
			break;
		}
		if(x == nn) y++, d = 3, f = 1;
		else if(x == 1) y++, d = 1, f = 1;
		else f = 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

