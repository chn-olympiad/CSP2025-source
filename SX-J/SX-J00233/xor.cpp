#include <bits/stdc++.h>
using namespace std;

int main() {
	//peropen("xor.in","r",stdin)
	//peropen("xor.out","w",stdout)
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	if (k == 0) {
		cout << "1";
		return 0;
	}
	sort(a, a + n);
	cout << a[n - 2];
	return 0;
}