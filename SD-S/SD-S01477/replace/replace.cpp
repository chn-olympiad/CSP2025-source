#include<bits/stdc++.h>
#define int long long
#define PII pair< int, int >

using namespace std;

const int N = 1e7 + 5, mod = 998244353;
int n, q;
string s1, s2;
vector< PII > a[N];

template< typename T, typename ... L > inline void read(T &x){
	bool f = true;
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9'){
		if (ch == '-') f = !f;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9'){
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	x = (f ? x : -x);
	return ;
}
template< typename T, typename ... L > inline void read(T &a, L && ... b){
	read(a);
	read(b ...);
}
int ksm(int a, int b, int p){
	int ans = 1;
	while (b){
		if (b & 1) ans = ans * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return ans;
}
signed main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out","w",stdout);
	read(n, q);
	for (int i = 1; i <= n; i++){
		cin >> s1 >> s2;
		int x = 0, y = 0, j;
		for (j = 0; j < s2.size(); j++){
			if (s2[j] != 'b') y++;
			else break;
		}
		for (j = 0; j < s1.size(); j++){
			if (s1[j] != 'b') x++;
			else break;
		}
		a[y-x+5000000].push_back({min(x, y) - 1, s1.size() - max(x, y) - 1});
	}
	for (int i = 0; i <= 10000000; i++) sort(a[i].begin(), a[i].end());
	while (q--){
		cin >> s1 >> s2;
		int x = 0, y = 0;
		for (int j = 0; j < s2.size(); j++){
			if (s2[j] != 'b') y++;
			else break;
		}
		for (int j = 0; j < s1.size(); j++){
			if (s1[j] != 'b') x++;
			else break;
		}
		int daan = 0;
		for (PII aaa : a[y-x+5000000]){
			if (aaa.first > min(x, y) - 1) break;
			if (aaa.second <= s1.size() - max(x, y) - 1) daan++;
		}
		printf("%lld\n", daan);
	}
	return 0;
}
//freopen("a.in", "w", stdin);
//freopen("a.in", "r", stdout);
//freopen("a.out", "w", stdin);
//freopen("a.out", "r", stdout);

