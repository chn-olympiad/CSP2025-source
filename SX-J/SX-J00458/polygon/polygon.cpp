#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 5005, M = 998244353;
ll n, arr[N], len, brr[100005], sum;

struct lk {
	ll a, b;
} q[N];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	sort(arr + 1, arr + n + 1);
	brr[++len] = arr[1];
	brr[++len] = arr[2];
	brr[++len] = arr[1] + arr[2];
	for (int i = 3; i <= n; i++) {
		ll x = len;
		q[i].a = x + 1;
		for (int j = 1; j <= len; j++)
			brr[++x] = arr[i] + brr[j];
		len = x, q[i].b = x;
	}
	for (int i = 3; i <= n; i++) {
		for (int j = q[i].b; j >= q[i].a; j--) {
			if (brr[j] <= arr[i] * 2)
				break;
			else {

				sum++;
			}

		}
	}
	cout << sum % M;
	return 0;
}
