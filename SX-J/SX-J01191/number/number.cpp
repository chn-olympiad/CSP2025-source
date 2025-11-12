#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	freopen("", "w", stdin);
	freopen("", "r", stdout);
	string a;
	int sum = 0, jl = 0;
	char sz[1000005] = {0};
	cin >> a;
	int l = a.length();
	for (int i = 0; i < l; i++) {
		if (a[i] == '1' || a[i] == '2' || a[i] == '3' || a[i] == '4' || a[i] == '5' || a[i] == '6' || a[i] == '7'
		        || a[i] == '8' || a[i] == '9' || a[i] == '0')
			sz[i] = a[i];
	}
	for (int i = 0; i < l; i++) {
		for (int i = 0; i < l; i++) {
			if (sz[i] < sz[i + 1]) {
				jl = sz[i];
				sz[i] = sz[i + 1];
				sz[i + 1] = jl;
			}
		}
	}

	for (int i = 0; i < l; i++) {
		cout << sz[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


















