#include <bits/stdc++.h>

using namespace std;

long long n, a[5005];

int main () {
	freopen ("stdin", "r", stdin);
	freopen ("stdout", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	cout << n * 3 - 1;
	fclose (stdin);
	fclose (stdout);
	return 0; 
}
