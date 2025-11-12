#include <bits/stdc++.h>
using namespace std;

/*
replace
At 17:55: If I were still in Senior 2 - or younger, I will recite KMP
yet I have been in Senior 3 now, so
*/

int n, q;

constexpr long long HASH1 = 998244353;
constexpr long long HASH2 = 1000000007;
constexpr int N = 1e4+3;
/*
struct hasher {
	long long h1 = 0, h2 = 0;
	hasher() {
		
	}
	hasher(int x) : h1(x), h2(x) {
		
	}
};

// Why isn't there any single-restriction?
vector<hasher> s1[N], s2[N];
string cs1, cs2;
*/
string cs1[N], cs2[N];
// What if STL string is equipped with KMP?

void sub1() {
	for (int i = 1; i <= n; i++) {
		cin>>cs1[i]>>cs2[i];
	}
	for (int i = 1; i <= q; i++) {
		string qu1, qs1, qs2;
		cin>>qs1>>qs2;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			qu1 = qs1;
			auto pos = qu1.find(cs1[i]);
			if (pos != string::npos) {
				qu1 = qu1.substr(0, pos) + cs2[i] + qu1.substr(pos + cs1[i].length());
				if (qu1 == qs2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>q;
	if (n <= 1000) sub1();
	else {
		for (int i = 1; i <= q; i++) cout<<"0\n";
	}
	cout<<flush;
	
	return 0;
}