#include <bits/stdc++.h>
using namespace std;
int t, a[10005][10005], n;
bool DEBUG = 0;

struct Mumber {
	int name;
	int good[3];
	bool used = 1;
};
Mumber m[10005];
int target;

bool cmp1(Mumber x, Mumber y) {
	if (x.used != 0)
		return 0;
	if (y.used != 0)
		return 1;
	return x.good[target] > y.good[target];
}

struct Unit {
	int name;
	int maxx = -1;
	bool over = 0;
	stack<int> use;
};

bool cmp2(Unit x, Unit y) {
	if (x.over != 0)
		return 0;
	if (y.over != 0)
		return 1;
	return x.maxx > y.maxx;
}
Unit u[3];
int r;

int all() {
	int sum = 0;
	for (int i = 1; i <= n / 2 && (m[i].used == 0); i++) {
		sum += m[i].good[target];
		u[target].use.push(m[i].name);
		if (DEBUG)
			cout << m[i].name << " into " << target << "(" << m[i].used << ")" << endl;
	}
	return sum;
}

bool cmp3(Mumber x, Mumber y) {
	return x.name < y.name;
}

bool cmp4(Unit x, Unit y) {
	return x.name < y.name;
}

int findM(int f) {
	for (int i = 1; i <= n; i++)
		if (m[i].name == f)
			return i;
	return -1;
}

int findU(int f) {
	for (int i = 1; i <= 2; i++)
		if (u[i].name == f)
			return i;
	return -1;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		r = 0;
		cin >> n;
		int N = n;
		for (int i = 1; i <= n; i++) {
			m[i].used = 0;
			m[i].name = i;
			for (int j = 0; j < 3; j++) {
				cin >> a[i][j];
				m[i].good[j] = a[i][j];
			}
		}
		target = 0;
		int uSum = 3;
		for (int i = 0; i < 3; i++) {
			u[i].name = i;
			u[i].over = 0;
			//u[i].use.clear();
		}
		for (int T = 3; (T > 0) && N > 0; T--) {
			for (int i = 0; i < uSum; i++) {
				sort(m + 1, m + n + 1, cmp3);
				while (u[target].over == 1) {
					target = (target + 1) % 3;
					if (DEBUG)
						cout << "DEBUGA" << endl;
				}
				sort(m + 1, m + n + 1, cmp1);
				u[target].maxx = all();
				target = (target + 1) % 3;
			}
			sort(u, u + 2, cmp2);
			while (!u[0].use.empty()) {
				m[findM(u[0].use.top())].used = 1;
				if (DEBUG)
					cout << u[0].use.top() << "out" << endl << "use.size=" << u[0].use.size() << endl;
				u[0].use.pop();
				N--;
				if (DEBUG)
					cout << "DEBUGB" << endl;
			}
			u[0].over = 1;
			if (DEBUG)
				cout << target << " " << u[0].maxx << endl;
			r += u[0].maxx;
			uSum--;
		}
		cout << r << endl;
	}
	return 0;
}