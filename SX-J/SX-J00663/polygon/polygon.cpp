#include <bits/stdc++.h>
using namespace std;

int main() {
	//fretorn(".in", "r", stdin)
	//fretorn("number.out","w",stdin)\
	int n;
	cin >> n;
	int a[11000000];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << a[n]-a[0];
	return 0;
}
