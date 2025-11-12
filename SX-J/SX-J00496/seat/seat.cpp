#include <bits/stdc++.h>
using namespace std;
string s[105];

int main() {
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int a;
	char x;
	int n, m;
	cin >> n >> m;
	cin >> a;
	s[a] = a;
	x = a;
	for (int i = 0; i < m * n - 1; i++) {
		cin >> a;
		s[a] = a;
	}
	int cnt;
	for (int i = 0; i < m * n; i++) {
		cnt++;
		if (cnt == x) {
			break;
		}
	}
	cout << "cnt" << cnt << endl;
	int lie, hang;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cnt--;
			if (cnt == 0) {
				lie = i;
				hang = j;
				break;
			}
		}
	}
	cout << lie << " ";
	if (lie % 2 == 0) {
		cout << n - hang + 1;
	} else {
		cout << hang;
	}
	return 0;
}