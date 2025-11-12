# include <bits/stdc++.h>
# include <cstdio>
# define ll long long
# define ull unsigned long long
# define endl '\n'
# define fst ios::sync_with_stdio (0); cin.tie (0); cout.tie (0);

using namespace std;

const int N = 2e5;
int n, q;
struct node {
	string a, b;
} arr[N];
string s1, s2;

int main () {
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i ++ ) {
		cin >> arr[i].a >> arr[i].b;
	}
	for (int i = 1; i <= q; i ++ ) {
		cin >> s1 >> s2;
		cout << 0 << endl;
	}
	return 0;
}
// Can you give me more points,CCF?
