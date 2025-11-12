#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>inline void read(T &x){
	x = 0; T w = 1; char ch = getchar();
	while (!isdigit(ch)){if (ch == '-')	w = -1; ch = getchar();}
	while (isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	x *= w;
}
template<typename T>inline void write(T x){
	if (x < 0)	putchar('-'), x = ~(x - 1);
	if (x > 9)	write(x / 10);
	putchar(x % 10 ^ 48);
}

int n, q, ans;

map<string, string> mp;
string s1, s2, t1, t2;

int main(){
	freopen("replace.in", "r", stdin), freopen("replace.out", "w", stdout);
	ios :: sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n >> q;
	for (int i = 1; i <= n; ++i){
		cin >> s1 >> s2;
		mp[s1] = s2;
	}
	while (q--){
		cin >> t1 >> t2;
		if (t1.length() != t2.length()){
			cout << "0\n";
			continue;
		}
		ans = 0;
		for (int l = 0; l < t1.length(); ++l)
			for (int r = l; r < t1.length(); ++r)
				if (mp[t1.substr(l, r - l + 1)] == t2.substr(l, r - l + 1)){
					if ((l == 0 || t1.substr(0, l) == t2.substr(0, l)) && (r == t1.length() - 1 || t1.substr(r + 1, t1.length() - 1 - r) == t2.substr(r + 1, t2.length() - 1 - r)))
						++ans;
				}
		cout << ans << '\n';
	}

	return 0;
}

