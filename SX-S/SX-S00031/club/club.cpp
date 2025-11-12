#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

int f[N][3], d[N];

struct F_college {
	int value, id;
} a[N];

struct S_college {
	int value, id;
} b[N];

struct T_college {
	int value, id;
} c[N];

bool cmpa(F_college, F_college);
bool cmpb(S_college, S_college);
bool cmpc(T_college, T_college);
int Max(int);

int main() {
	//freopen("club.in", "r", stdin);
	//freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		if (n == 1) {
			int x, y, z;
			cin >> x >> y >> z;
			cout << max(x, max(y, z)) << endl;
			continue;
		}
		if (n == 2) {
			for (int i = 1; i <= 2; i++)
				cin >> f[i][1] >> f[i][2] >> f[i][3];
			int m = INT_MIN;
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++)
					if (i != j)
						m = max(m, f[1][i] + f[2][j]);
			}
			cout << m << endl;
			continue;
		}

		for (int i = 1; i <= n; i++) {
			cin >> f[i][1] >> f[i][2] >> f[i][3];
			a[i].value = f[i][1], b[i].value = f[i][2], c[i].value = f[i][3];
			a[i].id = b[i].id = c[i].id = i;
		}

		sort(a + 1, a + n + 1, cmpa);
		sort(b + 1, b + n + 1, cmpb);
		sort(c + 1, c + n + 1, cmpc);

		long long a1, b1, c1;
		a1 = b1 = c1 = 0;
		for (int i = 1; i <= n / 2; i++) {
			a1 += a[i].value, b1 += b[i].value, c1 += c[i].value;
			d[a[i].id]++, d[b[i].id]++, d[c[i].id]++;
		}

		long long s = a1 + b1 + c1;
		for (int i = 1; i <= n; i++) {
			if (d[i] == 3) {
				int x = Max(i);
				if (x == 1)
					s = s - f[i][2] - f[i][3];
				else if (x == 2)
					s = s - f[i][1] - f[i][3];
				else
					s = s - f[i][1] - f[i][2];
			}
		}
		cout << s << endl;
	}
	return 0;
}

bool cmpa(F_college x, F_college y) {
	return x.value > y.value ? true : false;
}

bool cmpb(S_college x, S_college y) {
	return x.value > y.value ? true : false;
}

bool cmpc(T_college x, T_college y) {
	return x.value > y.value ? true : false;
}

int Max(int i) {
	int m = INT_MIN, id;
	for (int j = 1; j <= 3; j++) {
		if (m < f[i][j]) {
			m = f[i][j];
			id = j;
		}
	}
	return id;
}