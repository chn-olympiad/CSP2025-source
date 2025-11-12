#include <bits/stdc++.h>
using namespace std;
int n[5005];

bool cl(int q, int w, int e) {
	int r, t;
	if (q > w && q > e) {
		r = q;
		t = w + e;
	}
	if (w > q && w > e) {
		r = w;
		t = q + e;
	}
	if (e > w && e > q) {
		r = e;
		t = q + w;
	}
	if (t > r)
		return 1;
	else
		return 0;
}

bool cl(int q, int w, int e, int p) {
	int r, t;
	if (q > w && q > e && q > r) {
		r = q;
		t = w + e + r;
	}
	if (w > q && w > e && w > p) {
		r = w;
		t = q + e + p;
	}
	if (e > w && e > q && e > p) {
		r = e;
		t = q + w + p;
	}
	if (p > w && p > q && p > e) {
		r = p;
		t = q + w + e;
	}
	if (t > r)
		return 1;
	else
		return 0;
}

int main() {
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	int a;
	cin >> a;
	for (int i = 0; i < a; i++)
		cin >> n[i];
	int y = 0;
	for (int i = 0; i < a; i++) {
		if (i + 2 < a)
			if (cl(n[i], n[i + 1], n[i + 2]))
				y++;
		if (i + 3 < a)
			if (cl(n[i], n[i + 1], n[i + 2], n[i + 3]))
				y++;
	}
	cout << y;
	return 0;
}
