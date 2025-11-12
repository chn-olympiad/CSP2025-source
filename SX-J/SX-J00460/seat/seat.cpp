#include <bits/stdc++.h>
using namespace std;
int a[10005], l;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int s = n * m;
	for (int i = 1; i <= s; i++) {
		cin >> a[i];
	}
	int k = a[1];
	sort(a + 1, a + s + 1);
	for (int i = 1; i <= s ; i++) {

		if (a[i] == k) {
			l = s - i + 1;
			break;
		}
	}
	int hang = l % n;
	int lie = l / n;
	if (hang == 0) {
		if (lie % 2 != 0) {
			cout << lie << " " << n;
		}
		if (lie % 2 == 0) {
			cout << lie << " " << 1;
		}
	}
	if (hang != 0) {
		lie += 1;
		if (lie % 2 != 0) {
			cout << lie << " " << hang;
		}
		if (lie % 2 == 0) {
			cout << lie << " " << n - hang + 1;
		}
	}


	return 0;
}
