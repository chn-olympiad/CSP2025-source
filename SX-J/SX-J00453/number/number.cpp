#include <bits/stdc++.h>
using namespace std;
char q[1000010];
int a[1000010], ls = 0;

bool renyi(int x, int y) {
	if (x >= y) {
		return 1;
	} else {
		return 0;
	}
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	for (int i = 0; i <= 1000009; i++) {
		q[i] = 'A';
	}
	cin >> q;
	for (int i = 0; q[i] != 'A'; i++) {
		if (q[i] == '0' && q[i] == '1' && q[i] == '2' && q[i] == '3' && q[i] == '4' && q[i] == '5' && q[i] == '6'
		        && q[i] == '7' && q[i] == '8' && q[i] == '9') {
			ls++;
			a[ls] = q[i] - '0';
		}
	}
	sort(a + 1, a + 1 + ls, renyi);
	for (int i = 1; i <= ls; i++) {
		cout << a[i];
	}


}
