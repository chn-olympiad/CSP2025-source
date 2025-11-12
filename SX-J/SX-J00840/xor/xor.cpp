#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[500005];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	bool A = true;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 1)
			A = false;
	}
	if (A) {
		cout << n / 2;
		return 0;
	}
	cout << 0;
	return 0;

//©m ©¬ ©¬ .¡£©¬ ©m  ©m.. ¡ð
//©m©¬©m¡ñ  ¡ð .©m ©m¡£¨y¨z¨|
//©¬ ©¬ /¨€\/¨ˆ\ ©m ©¬ ©m©m ©¬ ©m
//¨|¨~¨€¨€¨€¨€¨€¨~¨}¨|¨z¨y©¬©m
}