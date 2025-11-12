#include <iostream>
#include <string>
using std::cin; using std::cout;

inline void freopen(std::string const && s) noexcept
{
	std::freopen((s + ".in").c_str(), "r", stdin),
	std::freopen((s + ".out").c_str(), "w", stdout);
}
int constexpr MOD{998244353};

long long solve(int a) noexcept
{
	if (a <= 2) return a;
	return a * solve(a - 1) % MOD;
}

int main() noexcept
{
	freopen("employ");
	std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	int m, n;
	cin >> n >> m;
	
	std::string s; cin >> s;
	int c;
	for (int i{0}; i < n; ++i) cin >> c;
	
	cout << solve(n);
	
	
	return 0;
}