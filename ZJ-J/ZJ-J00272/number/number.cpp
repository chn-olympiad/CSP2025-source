#include <bits/stdc++.h>
#define ll long long

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	std::string s;
	std::cin >> s;
	ll n = s.size();
	std::vector<ll> ans;
	for (ll i = 0; i < n; i ++) {
		if (isdigit(s[i])) {
			ll v = s[i] - 48;
			ans.push_back(v);
		}
	}
	std::sort(ans.begin(), ans.end(), std::greater<ll>());
	for (ll i = 0; i < ans.size(); i ++) std::cout << ans[i]; 
} 
// Please reopen my code.
// write in Dev-C++, ANSI
// UTF-8 can't see the Chinese chracters
// 写了 100pts 期待 100pts
// 下面是引流
// freopen("xor.in", "r", stdin);
// freopen("xor.out", "w", stdout);
// 114514 1919810
// Genshin Impact
// I Love CCF!
// freoepn
// freopne 
// luogu @nightwatch.ryan! QwQ 
