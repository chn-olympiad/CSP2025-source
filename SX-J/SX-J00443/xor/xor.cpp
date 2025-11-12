#include <bits/stdc++.h>
using namespace std;
#define N 500010
#define ll long long
ll a[N], b[N], sum, temp;
bool vis[N];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ll n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = b[i - 1] ^ a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == k) {
			//cout << i << endl;
			sum++;
			vis[i] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 1)
			continue;
		for (int j = i + 1; j <= n; j++) {
			if (vis[j] == 1) {
				i = j + 1;
				break;
			}
			if ((b[j]^b[i - 1]) == k) {
				sum++;
				//cout << i << " " << j << " " << b[i - 1] << " " << b[j] << " " << (b[j]^b[i - 1]) << endl;
				i = j + 1;
				break;
			}
		}
	}
//	for (int i = 1; i <= n; i++)
//		cout << (k ^ a[i]) << " ";
//	cout << endl;
//	for (int i = 1; i <= n; i++)
//		cout << b[i] << " ";
//	cout << endl;
//	cout << (2 ^ 3) << endl;
	cout << sum;
	return 0;
}
