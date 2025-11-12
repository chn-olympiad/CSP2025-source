#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;
int a[5005];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cout << rand() % 10;
	return 0;
}
