#include <bits/stdc++.h>
using namespace std;
int sr, sz[10000], sz1, jsq, i2;

int main() {
	cin >> sr;
	for (int i = 0; i < sr; i++) {
		cin >> sz[i];
	}
	for (int i = 3; i <= sr; i++) {
		for (int i1 = 0; i1 < sr - i; i1++) {
			for (i2 = i1; i2 < i1 + i; i2++)
				sz1 += sz[i2];
			if (sz1 >= sz[i2] * 2)
				jsq++;
		}
	}
	cout << jsq;
}