#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {

	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	int n;
	scanf("%lld", &n);
	int arr[n + 2];

	for (int i = 0; i < n; i ++ ) {
		scanf("%lld", &arr[i]);
	}

	sort(arr, arr + n);
	reverse(arr, arr + n);

	if (( arr[0] ) <  ( arr[1]  + arr[2] ) ) {
		printf("1");
	} else {
		printf("0");
	}
	return 0;
}
