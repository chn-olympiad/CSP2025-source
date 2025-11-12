#include <iostream>
#include <algorithm>
#include <stack>
#include <cstdio>
using namespace std;

const int MAXN = 5e5 + 5;
stack<int> stk[MAXN];
long long a[MAXN], pfx[MAXN], dp[MAXN];
long long dric[MAXN];
int n, k, dsz;

inline long long read(){
	long long num = 0, sign = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
		sign = (ch == '-' ? -1 : 1), ch = getchar();
	while(ch >= '0' && ch <= '9')
		num = (num << 1) + (num << 3) + ch - 48,
		ch = getchar();
	return sign > 0 ? num : -num;
}

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	n = read(), k = read();
	for(int i = 1; i <= n; i++)
		a[i] = read(), pfx[i] = pfx[i - 1] ^ a[i],
		dric[i] = pfx[i];
	sort(dric + 1, dric + 1 + n);
	dsz = unique(dric + 1, dric + 1 + n) - dric - 1;
	for(int i = 1; i <= n; i++)
		pfx[i] = lower_bound(dric + 1, dric + 1 + dsz, pfx[i]) - dric;
	int j = lower_bound(dric + 1, dric + 1 + dsz, k) - dric;
	if(dric[j] == k) stk[j].push(0);
	for(int i = 1; i <= n; i++){
		dp[i] = dp[i - 1];
		if(stk[pfx[i]].size())
			dp[i] = max(dp[i], dp[stk[pfx[i]].top()] + 1);
		int j = lower_bound(dric + 1, dric + 1 + dsz, k ^ dric[pfx[i]]) - dric;
		if(dric[j] != (k ^ dric[pfx[i]])) continue;
		while(stk[j].size() && dp[stk[j].top()] <= dp[i])
			stk[j].pop();
		stk[j].push(i);
	}
	cout<< dp[n]<< "\n";
	fclose(stdin); fclose(stdout);
	return 0;
}
