#include <bits/stdc++.h>
using namespace std;
const int X = 1e5+5;
long long t, n, tot, arr[X], brr[X], crr[X], aa, bb, cc;

struct jj {
	int a, b, c, id;
};
jj f[X];

struct kk {
	int d, id;
};
kk x[X];

bool cmp(jj x, jj y) {
	if (x.id != y.id)
		return x.id < y.id;
	else if (x.a != y.a)
		return x.a > y.a;
	else if (x.b != y.b)
		return x.b > y.b;
	else
		return x.c > y.c;
}

bool cmp1(kk x, kk y) {
	return x.d > y.d;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		int kk = n / 2;
		for (int i = 1; i <= n; i++) {
			cin >> f[i].a >> f[i].b >> f[i].c;
			if (f[i].a)
				f[i].id++;
			if (f[i].b)
				f[i].id++;
			if (f[i].c)
				f[i].id++;
		}
		sort(f + 1, f + n + 1, cmp);
		for (int i = 1; i <= n; i++) {
			if (f[i].id == 1) {
				if (f[i].a && aa + 1 <= kk)
					arr[++aa] = f[i].a;
				else if (bb + 1 <= kk)
					brr[++bb] = f[i].b;
				else if (cc + 1 <= kk)
					crr[++cc] = f[i].c;
				else if (f[i].b && bb + 1 <= kk)
					brr[++bb] = f[i].b;
				else if (aa + 1 <= kk)
					arr[++aa] = f[i].a;
				else if (cc + 1 <= kk)
					crr[++cc] = f[i].c;
				else if (f[i].c && cc + 1 <= kk)
					crr[++cc] = f[i].c;
				else if (aa + 1 <= kk)
					arr[++aa] = f[i].a;
				else if (bb + 1 <= kk)
					brr[++bb] = f[i].b;
			} else if (f[i].id == 2) {
				if (f[i].a && f[i].c && f[i].a > f[i].c && aa + 1 <= kk)
					arr[++aa] = f[i].a;
				else if (f[i].a && f[i].c && f[i].c > f[i].a && cc + 1 <= kk)
					crr[++cc] = f[i].c;
				else if (bb + 1 <= kk)
					brr[++bb] = f[i].b;
				else if (f[i].a && f[i].b && f[i].a > f[i].b && aa + 1 <= kk)
					arr[++aa] = f[i].a;
				else if (f[i].a && f[i].b && f[i].b > f[i].a && bb + 1 <= kk)
					brr[++bb] = f[i].b;
				else if (cc + 1 <= kk)
					crr[++cc] = f[i].c;
				else if (f[i].b && f[i].c && f[i].b > f[i].c && bb + 1 <= kk)
					brr[++bb] = f[i].b;
				else if (f[i].b && f[i].c && f[i].c > f[i].b && cc + 1 <= kk)
					crr[++cc] = f[i].c;
				else if (aa + 1 <= kk)
					arr[++aa] = f[i].a;
			} else if (f[i].id == 3) {
				x[1].d = f[i].a, x[2].d = f[i].b, x[3].d = f[i].c, x[1].id = 1, x[2].id = 2, x[3].id = 3;
				sort(x + 1, x + 4, cmp1);
				if (x[1].id == 1 && aa + 1 <= kk)
					arr[++aa] = x[1].d;
				else if (x[1].id == 2 && bb + 1 <= kk)
					brr[++bb] = x[1].d;
				else if (x[1].id == 3 && cc + 1 <= kk)
					crr[++cc] = x[1].d;
				else if (x[2].id == 1 && aa + 1 <= kk)
					arr[++aa] = x[2].d;
				else if (x[2].id == 2 && bb + 1 <= kk)
					brr[++bb] = x[2].d;
				else if (x[2].id == 3 && cc + 1 <= kk)
					crr[++cc] = x[2].d;
				else if (x[3].id == 1 && aa + 1 <= kk)
					arr[++aa] = x[3].d;
				else if (x[3].id == 2 && bb + 1 <= kk)
					brr[++bb] = x[3].d;
				else if (x[3].id == 3 && cc + 1 <= kk)
					crr[++cc] = x[3].d;
				memset(x, 0, sizeof x);
			}
		}
		for (int i = 1; i <= aa; i++)
			tot += arr[i];
		for (int i = 1; i <= bb; i++)
			tot += brr[i];
		for (int i = 1; i <= cc; i++)
			tot += crr[i];
		cout << tot << endl;
		tot = 0, aa = 0, bb = 0, cc = 0;
		memset(f, 0, sizeof f);
		memset(arr, 0, sizeof arr);
		memset(brr, 0, sizeof brr);
		memset(crr, 0, sizeof crr);
	}
	return 0;
}

