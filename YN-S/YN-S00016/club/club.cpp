#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int T;
const int MAXN = 1e5 + 5;
ll n, ans;
bool flaga, flagb, flagc;

struct student {
	ll a, b, c;
} arr[MAXN];

bool cmpa(student a, student b) {
	return (a.a > b.a);
}

bool cmpb(student a, student b) {
	return (a.b > b.b);
}

bool cmpc(student a, student b) {
	return (a.c > b.c);
}

void solvea() {
	sort(arr + 1, arr + 1 + n, cmpa);
	for (int i = 1; i <= (n >> 1); i++) {
		ans += arr[i].a;
	}
	cout << ans << endl;
}

void solveb() {
	sort(arr + 1, arr + 1 + n, cmpb);
	for (int i = 1; i <= (n >> 1); i++) {
		ans += arr[i].b;
	}
	cout << ans << endl;
}

void solvec() {
	sort(arr + 1, arr + 1 + n, cmpc);
	for (int i = 1; i <= (n >> 1); i++) {
		ans += arr[i].c;
	}
	cout << ans << endl;
}

void solveE() {
	for (int i = 1; i <= n; i++) {
		ans += max(arr[i].a, max(arr[i].b, arr[i].c));
	}
	cout << ans << endl;
}

bool check(ll members) {
	if (members > (n >> 1)) {
		return false;
	}
	return true;
}
ll ans1 = 0;

void solveD(ll depth, ll club, ll membera, ll memberb, ll memberc) {
	if (depth > n) {
		ans = max(ans, ans1);
//		cout << "ans1:" << ans1 << endl;
		return;
	}
	if (club == 1 && arr[depth].a) {
		membera++;
		ans1 += arr[depth].a;
	}
	if (club == 2 && arr[depth].b) {
		memberb++;
		ans1 += arr[depth].b;
	}
	if (club == 3 && arr[depth].c) {
		memberc++;
		ans1 += arr[depth].c;
	}
	if (!check(membera)) {
		ans1 -= arr[depth].a;
		membera--;
		return;
	}
	if (!check(memberb)) {
		ans1 -= arr[depth].b;
		memberb--;
		return;
	}
	if (!check(memberc)) {
		ans1 -= arr[depth].c;
		memberc--;
		return;
	}
//	cout << "depth:" << depth << " club:" << club << " membera:" << membera << " memberb:" << memberb << " memberc:" <<
//	     memberc << endl;
	solveD(depth + 1, 1, membera, memberb, memberc);
	solveD(depth + 1, 2, membera, memberb, memberc);
	solveD(depth + 1, 3, membera, memberb, memberc);
	if (club == 1) {
		membera--;
		ans1 -= arr[depth].a;
	}
	if (club == 2) {
		memberb--;
		ans1 -= arr[depth].b;
	}
	if (club == 3) {
		memberc++;
		ans1 -= arr[depth].c;
	}
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i].a >> arr[i].b >> arr[i].c;
		if (arr[i].b || arr[i].c) {
			flaga = false;
		}
		if (arr[i].a || arr[i].c) {
			flagb = false;
		}
		if (arr[i].a || arr[i].b) {
			flagc = false;
		}
	}
	if (flaga) {
		solvea();
	} else if (flagb) {
		solveb();
	} else if (flagc) {
		solvec();
	} else {
		ans = -1;
		solveD(0, 1, 0, 0, 0);
		cout << ans << endl;
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while (T--) {
		ans = 0;
		flaga = 1;
		flagb = 1;
		flagc = 1;
		solve();
	}
	return 0;
}