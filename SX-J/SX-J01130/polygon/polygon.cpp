#include <bits/stdc++.h>
using namespace std;
int n,  sum = 0;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = n; i >= 0; i--) {
		sum += (i - 1);
	}
	cout << sum ;
	return 0;
}
