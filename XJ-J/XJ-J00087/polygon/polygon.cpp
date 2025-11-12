#include <iostream>
#include <vector>
using namespace std;
long long m;
bool isValid(vector<long long> &lens) {
	long long Max = 0, total = 0;
	for (long long i : lens) {
		total += i;
		Max = max(Max, i);
	}
	return total > Max * 2;
}
vector<long long> fact(5001);
long long f(long long num) {
	if (fact[num] == 0) {
		fact[num] = (num * f(num - 1));
	}
	return fact[num];
}
long long c(long long m, long long n) {
	return (f(n)) / (f(m) * f(n - m)) % 998244353;
}
long long ans = 0;
vector<long long> lens;
vector<long long> index;
vector<bool> isUsed;
vector<long long> l;
void dfs(long long step, long long n) {
	if (step > n) {
		if (isValid(l)) ans++;
		return;
	}
	for (long long num = index[step - 1] + 1; num <= m; num++) {
		if (!isUsed[num] || (step > 3 && isValid(l))) {
			index[step] = num;
			isUsed[step] = true;
			l.push_back(lens[index[step]]);
			dfs(step + 1, n);
			l.pop_back();
			index[step] = 0;
			isUsed[step] = false;
		}
	}
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	long long n;
	cin >> m;
	n = m;
	fact[0] = fact[1] = 1;
	bool all_1 = true;
	lens.resize(m + 1, 0);
	index.resize(n + 1, 0);
	isUsed.resize(n + 1, 0);
	for (long long i = 1; i <= m; i++) {
		cin >> lens[i];
		if (lens[i] != 1) all_1 = false;
	}
	if (all_1) {
		for (long long i = 3; i <= n; i++) {
			ans = (ans + c(i, n) % 998244353) % 998244353;
		}
		cout << ans;
		return 0;
	}
	for (long long cnt = 3; cnt <= n; cnt++) {
		dfs(1, cnt);
		l.clear();
	}
	cout << ans;
	return 0;
}
