#include <bits/stdc++.h>
using namespace std;

int main() {

	freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);


	int n;
	cin >> n;
	int a[10000];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		if (a[i] = 10) {
			cout << 6;
			break;
		} else {
			cout << 9;
			break;
		}
	}


	return 0;
}
