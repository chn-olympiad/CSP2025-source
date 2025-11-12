#include <bits/stdc++.h>

bool stmb;

using namespace std;

const int N = 200010;

int n, q;
string s[N][2];

template <typename type>
void read(type &res) {
	type x = 0, f = 1;
	char c = getchar();
	for (; c < 48 || c > 57; c = getchar()) f = (c == '-') ? -f : f;
	for (; c > 47 && c < 58; c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	res = f * x;
}

template <typename type, typename ...Args>
void read(type &x, Args &...args) {read(x), read(args...);}

void FileIO() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
}

bool edmb;

int main() {
//	cerr << (&stmb - &edmb) / 1024.0 / 1024.0 << '\n';
	FileIO();
	read(n, q);
	for (int i = 1; i <= n; i++) cin >> s[i][0] >> s[i][1];
	for (int i = 1; i <= q; i++) {
		string t1 = "", t2 = "";
		cin >> t1 >> t2;
		int ans = 0;
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < (int)t1.size(); k++) {
				string temp = t1.substr(k, t1.size() - k);
//				cerr << temp << endl;
				auto pos = temp.find(s[j][0]);
				if (pos == string::npos) break;
//				cerr << pos << endl;
				string bg = t1.substr(0, pos);
				string ed = "";
//				string ed = temp.substr(pos + s[j][0].size(), temp.size() - (pos + s[j][0].size()));
				for (int ll = pos + s[j][0].size(); ll < (int)temp.size(); ll++) ed.push_back(temp[ll]);
				string aft = bg + s[j][1] + ed;
//				cerr << bg << ' ' << ed << '\n';
//				cerr << aft << '\n';
				if (aft == t2) ans++;
//				k = pos + s[j][0].size() - 1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

