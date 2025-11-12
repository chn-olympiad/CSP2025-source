#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	FILE *fin, *fout;
	fin = fopen("club.in", "rb");
	fout = fopen("club.out", "wb");
	int t, n;
	int a[t], b[t], c[t];
	fscanf(fopen("club.in", "rb"), "%d", t);
	for (int i = 0; i < t; i++) {
		fscanf(fin, "%d", n);
		for (int j = 0; j < n; j++) {
			fscanf(fin, "%d", a[i]);
			fscanf(fin, "%d", b[i]);
			fscanf(fin, "%d", c[i]);
		}
	}
	int i, j, k;
	int x, y, z;
	for (int i = 0; i < t; i++) {
		if (a[i] > b[i] && a[i] > c[i]) {
			if (i < n / 2) {
				x = x + a[i];
				i + 1;
			}
		} else if (b[i] > a[i] && b[i] > c[i]) {
			if (j > n / 2) {
				y = y + b[i];
				j + 1;
			}
		} else if (c[i] > a[i] && c[i] > b[i]) {
			if (k > n / 2) {
				z = z + a[i];
				k + 1;
			}
		}
	}
	int l = x + y + z;
	fprintf(fout, "%d", l);
	return 0;
}