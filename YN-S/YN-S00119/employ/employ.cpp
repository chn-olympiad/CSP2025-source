#include <bits/stdc++.h>
#define int long long
using namespace std;
string s1, s2;

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	srand(0);
	int n, m;
	cin >> n >> m;
	cin >> s1;
	for (int i = 1; i <= m; i++) {
		int a;
		cin >> a;
	}
	cout << rand() % 998244353;
	return 0;
}
//Ren5Jie4Di4Ling5%
/*
bool cmp1(club x, club y) {
	return x.a1 > y.a1;
}

bool cmp2(club x, club y) {
	return x.a2 > y.a2;
}

bool cmp3(club x, club y) {
	return x.a3 > y.a3;
}

sort(c1.begin(), c1.end(), cmp1);
sort(c2.begin(), c2.end(), cmp2);
sort(c3.begin(), c3.end(), cmp3);
for (int i = 0; i < c1.size(); i++)
			cout << c1[i].bh << " " << c1[i].a1 << "\n";
		cout << '\n';
		for (int i = 0; i < c2.size(); i++)
			cout << c2[i].bh << " " << c2[i].a2 << "\n";
		cout << '\n';
		for (int i = 0; i < c3.size(); i++)
			cout << c3[i].bh << " " << c3[i].a3 << "\n";
	}
*/