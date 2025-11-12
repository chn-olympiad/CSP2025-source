#include <bits/stdc++.h>
using namespace std;
long long a[200];
long long n, m;

bool cmp(long long q, long long w) {
	return q > w;
}
long long sum;

int main() {

	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	long long l = n * m;
	for (int i = 1; i <= l; i++) {
		cin >> a[i];
	}
	long long chengji = a[1];
	sort(a + 1, a + l + 1, cmp);
	for (int i = 1; i <= l; i++) {
		if (chengji == a[i])
			sum = i;
	}
	long long lie = sum / n;
	if (sum % n != 0) {
		lie += 1;
	}
	long long hang = sum % n;
	if (hang == 0) {
		hang = n;
	}
	if (lie % 2 == 0) {
		hang = n - hang + 1;
	}
	cout << lie << " " << hang;
	return 0;
}
