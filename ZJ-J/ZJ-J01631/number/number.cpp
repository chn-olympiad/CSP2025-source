//Luogu 743373-Vitamin_B:)
//ZJ-J01631
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;

int n;

char a[1000005];

string s;

int main () {
//	freopen ("number4.in", "r", stdin);
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	ios::sync_with_stdio (0);
	cin.tie (0);
	cout.tie (0);

	cin >> s;

	for (const char& i : s)
		if (i >= '0' && i <= '9')
			a[n ++] = i;

	sort (a, a + n, greater <char> ());

	for (int i = 0; i < n; ++ i)
		cout << a[i];

	return 0;
}
