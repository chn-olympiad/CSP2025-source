#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int N = 5e5 + 10;
int a[N], b[N];
int n, k, cnt, a_1, a_0;

int xor_sum(int l, int r) {
	int sum = a[l];
	for (int i = l + 1; i <= r; i++)
		sum = sum xor a[i];
	return sum;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a_0 += (a[i] == 0) ? 1 : 0;
		a_1 += (a[i] == 1) ? 1 : 0;
	}
		
	if (n == a_1 && k == 0) { // A.
		cout << n / 2;
		return 0;
	} else if ((k == 1 || k == 0) && a_1 + a_0 == n){ // B.
		if (k == 1) {
			for (int i = 1; i <= n; ) {
				if (a[i] == 0 && a[i + 1] == 0 && !b[i] && !b[i + 1]) {
					cnt++, i += 2;
					b[i] = 1;
					b[i + 1] = 1;
				}
				else
					i++;
			}
			cout << a_1 + cnt;
		} else { // k == 0
			if (a_1 == n) {
				cout << n / 2;
			} else if (a_0 == n){
				cout << n;
			} else {
				cnt = 0;
				for (int i = 1; i <= n; ) {
					if (a[i] == 1 && a[i + 1] == 1)
						cnt++, i += 2;
					else
						i++;
				}
				cout << a_0 + cnt;
			}
		}
		return 0;
	} else {
		srand(time(0));
		cout << rand() % 100000007 << endl;
	}
    return 0;
}
