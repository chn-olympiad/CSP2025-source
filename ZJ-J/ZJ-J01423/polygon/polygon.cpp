#include <bits/stdc++.h>

#define debug(x) cerr << #x << ": " << x << '\n'

using namespace std;

typedef long long LL;

inline LL read() { LL x = 0, f = 1; char ch; while(!isdigit(ch = getchar())) if (ch == '-') f = -1; do x = (x << 3) + (x << 1) + (ch ^ 48); while(isdigit(ch = getchar())); return x * f; }

/*vector<bool> b;
void dfs(int n, int x) {
	if (x > n) return ;
	b[x] = false; dfs(n, x + 1);
	b[x] = true;  dfs(n + 1, x + 1);
}

struct pai{
	int pre, maxx;
};*/

int get_sum(vector<int>a) {
	int res = 0;
	for (int it : a) res += it;
	return res;
}
int get_max(vector<int>a) {
	int res = 0;
	for (int it : a) res = max(it, res);
	return res;
}
bool check(int dep, int sum, int maxx) {
	return (dep >= 3 ? (sum > 2 * maxx) : false);
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	int n = read(), ans = 0;
	vector<int> a(n + 1); //b.resize(n + 1, 1);
	// vector<vector<pai> > init(n + 1, vector<pai>(n + 1));
	for (int i = 1; i <= n; i++) a[i] = read();
	sort(a.begin() + 1, a.end());
	
	if (n == 3) {
		if (!(a[1] + a[2] > a[3])) 	return cout << 0 << '\n', 0;
		if (!(a[1] + a[3] > a[2]))	return cout << 0 << '\n', 0;
		if (!(a[2] + a[3] > a[1]))	return cout << 0 << '\n', 0;
		return cout << 1 << '\n', 0;
	}
	
	if (n == 4) {
		ans += check(3, get_sum({a[1], a[2], a[3]}), a[3]);
		ans += check(3, get_sum({a[1], a[2], a[4]}), a[4]);
		ans += check(3, get_sum({a[1], a[3], a[4]}), a[4]);
		ans += check(3, get_sum({a[2], a[3], a[4]}), a[4]);
		ans += check(4, get_sum({a[1], a[2], a[3], a[4]}), a[4]);	
		return cout << ans << '\n', 0;
	}
	
	if (n == 5) {
		ans += check(3, get_sum({a[1], a[2], a[3]}), a[3]);
		ans += check(3, get_sum({a[1], a[2], a[4]}), a[4]);
		ans += check(3, get_sum({a[1], a[2], a[5]}), a[5]);
		ans += check(3, get_sum({a[1], a[3], a[4]}), a[4]);
		ans += check(3, get_sum({a[1], a[3], a[5]}), a[5]);
		ans += check(3, get_sum({a[1], a[4], a[5]}), a[5]);
		ans += check(3, get_sum({a[2], a[3], a[4]}), a[4]);
		ans += check(3, get_sum({a[2], a[3], a[5]}), a[5]);
		ans += check(3, get_sum({a[2], a[4], a[5]}), a[5]);
		ans += check(3, get_sum({a[3], a[4], a[5]}), a[5]);
		ans += check(4, get_sum({a[1], a[2], a[3], a[4]}), a[4]);
		ans += check(4, get_sum({a[1], a[2], a[3], a[5]}), a[5]);	
		return cout << ans << '\n', 0;
	}
	
	if (n == 6) {
		ans += check(3, get_sum({a[1], a[2], a[3]}), a[3]);
		ans += check(3, get_sum({a[1], a[2], a[4]}), a[4]);
		ans += check(3, get_sum({a[1], a[2], a[5]}), a[5]);
		ans += check(3, get_sum({a[1], a[2], a[6]}), a[6]);
		
		ans += check(3, get_sum({a[1], a[3], a[4]}), a[4]);
		ans += check(3, get_sum({a[1], a[3], a[5]}), a[5]);
		ans += check(3, get_sum({a[1], a[3], a[6]}), a[6]);
		
		ans += check(3, get_sum({a[1], a[4], a[5]}), a[5]);
		ans += check(3, get_sum({a[1], a[4], a[6]}), a[6]);
		
		ans += check(3, get_sum({a[1], a[5], a[6]}), a[6]);
		
		ans += check(3, get_sum({a[2], a[3], a[4]}), a[4]);
		ans += check(3, get_sum({a[2], a[3], a[5]}), a[5]);
		ans += check(3, get_sum({a[2], a[3], a[6]}), a[6]);
				
		ans += check(3, get_sum({a[2], a[4], a[5]}), a[5]);
		ans += check(3, get_sum({a[2], a[4], a[6]}), a[6]);
		
		ans += check(3, get_sum({a[2], a[5], a[6]}), a[6]);
		
		ans += check(3, get_sum({a[3], a[4], a[5]}), a[5]);
		ans += check(3, get_sum({a[3], a[5], a[6]}), a[6]);
		
		ans += check(4, get_sum({a[1], a[2], a[3], a[4]}), a[4]);
		ans += check(4, get_sum({a[1], a[2], a[3], a[5]}), a[5]);
		ans += check(4, get_sum({a[1], a[2], a[3], a[6]}), a[6]);	
		
		ans += check(4, get_sum({a[1], a[2], a[4], a[5]}), a[5]);
		ans += check(4, get_sum({a[1], a[2], a[4], a[6]}), a[6]);	
		ans += check(4, get_sum({a[1], a[2], a[5], a[6]}), a[6]);		
		
		ans += check(4, get_sum({a[2], a[3], a[4], a[5]}), a[5]);
		ans += check(4, get_sum({a[2], a[3], a[4], a[6]}), a[6]);
		
		ans += check(4, get_sum({a[2], a[4], a[5], a[6]}), a[6]);
		
		ans += check(4, get_sum({a[3], a[4], a[5], a[6]}), a[6]);

		ans += check(5, get_sum({a[1], a[2], a[3], a[4], a[5]}), a[5]);
		ans += check(5, get_sum({a[1], a[2], a[3], a[4], a[6]}), a[6]);

		ans += check(6, get_sum({a[1], a[2], a[3], a[4], a[5], a[6]}), a[6]);		
		return cout << ans << '\n', 0;
	}

	cout << 0 << '\n';
	 
	return 0;
}

/*	// qu_jian pre and max
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			init[i][j].pre = init[i][j - 1].pre + a[j];
			init[i][j].maxx = max(init[i][j - 1].maxx, a[j]);
		}
	}
*/		