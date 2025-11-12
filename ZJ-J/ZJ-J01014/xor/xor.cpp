#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, k;
int o, low[1000010], high[1000010];
int a[1000010];

string Zh1(int x) {
	string xx = "";
	while(x) {
		char t = (x % 2) + '0';
		xx = t + xx;
		x /= 2;
	}
	return xx;
}

string R(string x) {
	string H = "";
	for(int i = 0; i < x.size(); ++i)
		H = x[i] + H;
	return H;
}

int Zh2(string y) {
	int cnt = 0;
	string x = R(y);
	for(int i = 0; i < x.size(); ++i) {
		int t = 1;
		if(x[i] == '0')	t = 0;
		cnt += t * pow(2, i);
	}
	return cnt;
}


string F(string x, string y) {
	string K = "";
	string q = R(x), p = R(y);
	int w = max(q.size(), p.size());
	for(int i = 0; i < w; ++i) {
		if(i >= q.size())	K = p[i] + K;
		else if(i >= p.size())	K = q[i] + K;
		else {
			if(q[i] != p[i])	K = '1' + K;
			else	K = '0' + K;
		}
	}
	return K;
}

signed main() {
	
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	scanf("%lld %lld", &n, &k);
	for(int i = 1; i <= n; ++i)
		scanf("%lld", &a[i]);
	for(int i = 1; i <= n; ++i) {	
		
		for(int j = 1; j <= i; ++j) {
			int ans = 0;
			for(int l = j; l <= i; ++l) {
				string y = Zh1(a[l]);
				string x = Zh1(ans);
				string L = F(x, y);
				ans = Zh2(L);
			}
			if(ans == k) {
				low[++o] = j;
				high[o] = i;
			}
		}
	}
	if(o == 0 || o == 1) {
		printf("%lld", o);
		return 0;
	}
	int maxn = 0;
	for(int i = 1; i <= n; ++i) {
		int minn = 1e9;
		for(int j = 1; j <= o; ++j)
			if(low[j] == i)
				minn = min(minn, high[j]);
		if(minn == 1e9)	continue;
		maxn++;
		i = minn;
	}
	printf("%lld", maxn);
	
	return 0;
}