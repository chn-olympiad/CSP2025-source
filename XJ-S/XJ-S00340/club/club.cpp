#include <bits/stdc++.h>
using namespace std;

typedef vector <int> vi;
typedef pair <int, int> ii;

int T, n, w, ans, m[100010];
vi s[3];
ii d[3];

bool cmp(const int &x, const int &y) {
	return m[x] < m[y];
}

int main() {
	for (freopen("club.in", "r", stdin), freopen("club.out", "w", stdout),
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0),
        cin >> T; T--; cout << ans << endl, ans = 0) {
		for (int i = 0; i < 3; i++)
		    s[i].clear();
		
		cin >> n;
		for (int i = 1; i <= n; 
		    sort(d, d + 3),
			s[d[2].second].push_back(i),
			ans += d[2].first,
			m[i] = d[2].first - d[1].first, i++) 
			for (int j = 0; j < 3; j++)
				cin >> d[j].first, d[j].second = j;

		int x = 3;
		for (int i = 0; i < 3; i++)
			if (s[i].size() > n / 2)
				x = i; 

		if (x != 3) {
			int nm = s[x].size() - n / 2;
			sort(s[x].begin(), s[x].end(), cmp);
			for (int i = 0; i < nm; i++)
				ans -= m[s[x][i]];
		}
	}

	return 0;
}
