#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100010

struct Node {
	int a, n;//ÂúÒâ¶È£¬±àºÅ
} s1[N], s2[N], s3[N], s[N + 1000], m1, m2, m3;

bool cmp(Node x, Node y) {
	if (x.a != y.a)
		return x.a > y.a;
	return x.n < y.n;
}


bool vis[N];
int sum, t[10], m11, m22, m33, a = 1, b = 1, c = 1;

void update(Node x, int n) {
	sum += x.a;
	vis[x.n] = 1;
	if (n == 1)
		a++;
	if (n == 2)
		b++;
	if (n == 3)
		c++;
	t[n]++;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T, a1, a2, a3;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a1 >> a2 >> a3;
			s1[i] = {a1, i};
			s2[i] = {a2, i};
			s3[i] = {a3, i};
		}

		sum = 0;
		memset(vis, 0, sizeof(vis));
		memset(t, 0, sizeof(t));

		int m = n / 2;
		sort(s1 + 1, s1 + n + 1, cmp);
		sort(s2 + 1, s2 + n + 1, cmp);
		sort(s3 + 1, s3 + n + 1, cmp);


		a = 1, b = 1, c = 1;
		for (int i = 1; i <= n; i++) {
			//cout << s1[a].a << " " << s2[b].a << " " << s3[c].a << endl;
			if (s1[a].a >= s2[b].a && s1[a].a >= s3[c].a) {
				if (t[1] < m)
					update(s1[a], 1);
				else if (s2[b].a >= s3[c].a)
					update(s2[b], 2);
				else
					update(s3[c], 3);
				//cout << "1" << " " << s1[a].n << " " << s1[a].a << endl;
			} else if (s2[b].a >= s1[a].a && s2[b].a >= s3[c].a) {
				if (t[2] < m)
					update(s2[b], 2);
				else if (s1[a].a >= s3[c].a)
					update(s1[a], 1);
				else
					update(s3[c], 3);
				//cout << "2" << " " << s2[b].n << " " << s2[b].a << endl;
			} else if (s3[c].a >= s2[b].a && s3[c].a >= s1[a].a) {
				if (t[3] < m)
					update(s3[c], 3);
				else if (s2[b].a >= s1[a].a)
					update(s2[b], 2);
				else
					update(s1[a], 1);
				//cout << "3" << " " << s3[b].n << " " << s3[b].a << endl;
			}
			while (vis[s1[a].n] == 1 && a < n)
				a++;
			while (vis[s2[b].n] == 1 && b < n)
				b++;
			while (vis[s3[c].n] == 1 && c < n)
				c++;
			//cout << a << b << c << endl;
			//cout << vis[1] << " " << vis[2] << " " << vis[3] << " " << vis[4] << endl;
		}
		cout << sum << endl;
	}
	return 0;
}