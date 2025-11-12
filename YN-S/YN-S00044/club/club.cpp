#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000

int main() {
//	freopen("club.in", "r", stdin);
//	freopen("club.out", "w", stdout);

	int t, n;
	cin >> t;
	int A[MAXN], B[MAXN], C[MAXN];
	while (t > 0) {
		cin >> n;
		if (n % 2 == 0) {
			for (int i = 0; i < n; i++)
				cin >> A[i] >> B[i] >> C[i];
		}
		t -= 1;
	}

	int a = 0, b = 0, c = 0, a1 = 0, b1 = 0, c1 = 0, num = n / 2;

	int mid;
	for (int i = 0; i < n; i++) {
		mid = max(A[i], B[i]);
		if (mid > B[i] and mid > C[i]) {
			a++;
			a1 += A[i];
		} else if (mid > A[i] and mid > C[i]) {
			b++;
			b1 += B[i];
		} else {
			c++;
			c1 += C[i];
		}
	}

	cout << a1 << endl;
	cout << b1 << endl;
	cout << c1 << endl;

//	fclose(stdin);
//	fclose(stdout);

	return 0;
}
