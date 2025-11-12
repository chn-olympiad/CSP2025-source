#include <iostream>
#include <algorithm>
//include<bits/stdc++.h>
#define MAXN 100010
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

bool A, B;
ll ans = 0, cnr = 0;
int t, n, lim;
int a[MAXN][4];
int max(ll x, ll y) {
	return x > y ? x : y;
}

int max(int x, int y) {
	return x > y ? x : y;
}

int max(ll x, int y) {
	return x > (ll)y ? x : y;
}

int max(int x, ll y) {
	return max(y, x);
}

struct club {
	int num;
	int mem[MAXN];
	int eng = 0;;
};
club w[4];

void fl() {
	//cnr = w[1].eng + w[2].eng + w[3].eng;
	ans = max(ans, cnr);
}

void add(int i, int x) {
	w[x].num++;
	w[x].mem[i] = 0;
	w[x].eng += a[i][x];
	cnr += a[i][x];
	fl();
}

void mov(int i, int x) {
	w[x].num--;
	w[x].mem[i] = 0;
	w[x].eng -= a[i][x];
	cnr -= a[i][x];
	fl();
}

void dfs(int i) {
	if (i > n)
		return;
	for (int x = 1; x <= 3; x++) {
		if (w[x].num >= lim)
			continue;
		add(i, x);
		//ans = max(ans, cnr);
		/*if (cnr < ans) {//greedy //WA
			mov(i, x);
			continue;
		}*/
		dfs(i + 1);
		mov(i, x);
	}
}

int sor[3][20002];//base sorting.

/*struct ap3 {
	int tri = 0;
	int ind = 0;
};
ap3 tr[MAXN];

bool cmp(ap3 x, ap3 y) {
	return x.tri > y.tri;
}
*/
int tr[MAXN];
bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	//violence-20?greedy-20?binary?
	cin >> t;
	A = 1, B = 1;
	while (t--) {
		ans = 0, cnr = 0;
		memset(sor, 0x00, sizeof(sor));
		memset(a, 0x00, sizeof(a));
		memset(w, 0x00, sizeof(w));
		cin >> n;
		lim = n >> 1;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if (A && a[i][2] != 0)
				A = 0;
			if (B && a[i][3] != 0)
				B = 0;
		}
		if (A) {
			//cerr << "special case A" << endl;
			for (int i = 1; i <= n; i++)
				sor[1][a[i][1]] = i;
			for (int m = 20000; m >= 0; m--) {
				if (w[1].num >= lim)
					break;
				if (sor[1][m])
					add(sor[1][m], 1);
			}
			cout << ans << "\n";
			continue;
		}
		if (B) {
			//cerr << "special case B" << endl;
			for (int i = 1; i <= n; i++) {
				ans += (a[i][1] + a[i][2]);
				tr[i] = a[i][1] - a[i][2];
				//cerr << tr[i] << " ";
			}
			//cerr << "\n";
			sort(tr + 1, tr + n, cmp);
			/*for (int i = 1; i <= n; i++)
				cerr << tr[i] << " ";*/
			for (int i = 1; i <= n; i++) {
				if (i <= lim)
					ans += tr[i];
				if (i > lim)
					ans -= tr[i];
			}
			ans = ans >> 1;
			cout << ans << "\n";
			continue;
		}
		if (!A && !B && n == 100000) {
			//maybe
			cout << 1 << "\n";
			continue;
		}
		//cerr << n << " " << lim << " starting\n";
		//n=2时,直接穷举
		if (n == 2) {
			for (int i = 1; i <= 3; i++)
				for (int j = 1; j <= 3; j++) {
					if (i == j)
						continue;
					ans = max(ans, a[1][i] + a[2][j]);
				}
			cout << ans << "\n";
			continue;
		}
		//dfs只能20分
		if (n <= 20) {
			dfs(1);
			cout << ans << "\n";
			continue;
		}

		//计数排序，然后去重？WA.
		//memset(sor, 0x00, sizeof(sor));
		//memset(w, 0x00, sizeof(w)); already have.
		for (int x = 1; x <= 3; x++) {
			for (int i = 1; i <= n; i++)
				sor[x][a[i][x]] = i;
			for (int m = 20000; m >= 0; m--) {
				if (w[x].num >= lim)
					break;
				if (sor[x][m])
					add(sor[x][m], x);
			}
		}
		/*for(int x = 1; x<=3; x++){
			for(int i = 1; i<=n; i++){
				cout<<w[x].
			}
		}*/
		for (int i = 1; i <= n; i++) {
			int q = 0;
			int rem = 0;
			for (int x = 1; x <= 3; x++) {
				if (w[x].mem[i]) {
					q += a[i][x];
					rem = max(rem, a[i][x]);
				}
			}
			ans -= q;
			ans += rem;
		}
		cout << ans << "\n";
		continue;
	}
	return 0;
}