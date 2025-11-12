#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 505, mod = 998244353;

int n, m, c[N], p[N];
string s;

void solve()
{
	cin >> n >> m;
	cin >> s; s = " " + s;
	for(int i = 1; i <= n; i ++) cin >> c[i];	
	for(int i = 1; i <= n; i ++) p[i] = i;
	
	if(n <= 10){
		ll res = 0;
		do{
			int cnt = 0; // 之前放弃的人数
			for(int i = 1; i <= n; i ++){
				if(s[i] == '0' || cnt >= c[p[i]]) cnt ++;
			}
			if(n - cnt >= m){
				res ++;
				if(res >= mod) res -= mod;
			}
		}while(next_permutation(p+1,p+n+1));
		cout << res << '\n';
	}
	else if(m == 1){
		vector<int> cnt(n + 1);
		for(int i = 1; i <= n; i ++){
			cnt[i] = cnt[i - 1] + (s[i] == '0');
		}
		vector<ll> fac(n + 1);
		for(int i = 1; i <= n; i ++){
			fac[i] = fac[i - 1] * i % mod;
		}
		ll res = 1;
		for(int i = 1; i <= n; i ++){
			// 找到第一个s[j]>=c[i]，答案乘上 (j-1)!
			int p = lower_bound(cnt.begin(), cnt.end(), c[i]) - cnt.begin();
			res = res * fac[j - 1] % mod;
		}
		cout << res << '\n';
	} 
	else{
		// 状压，设f[i]表示当前参加面试的人为i时能够至少录用m人的数量
		// 初始化所有二进制里有 
		cout << 0 << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	solve();
	return 0;
}

// 35 + 48+? + 10 + 20
