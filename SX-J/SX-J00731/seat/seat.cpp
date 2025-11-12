#include <bits/stdc++.h>
using namespace std;
int n, m;
int t[200];

int seat1(int a) {
	if (a % n == 0)
		return a / n;
	else
		return a / n + 1;
}

int seat2(int a) {
	int aa = seat1(a);
	int bb = a % n;
	if (bb == 0)
		bb = n;
	if (aa % 2 == 1)
		return bb;
	if (aa % 2 == 0)
		return n - bb + 1;
	return 0;
}

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> t[i];
	int a = t[1];
	sort(t + 1, t + m *n + 1, cmp);
	for (int i = 1; i <= m * n; i++) {
		if (t[i] == a) {
			cout << " " << seat1(i) << " " << seat2(i) ;
			return 0;
		}
	}
	return 0;
}
