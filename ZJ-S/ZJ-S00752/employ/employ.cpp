#include <bits/stdc++.h>
using namespace std;
const int N = 510;
int n, m, a[N], s[N], tot[N], cnt, f[(1 << 18) + 10][20];
char ch;
int calc(int t) {
    int cnt = 0;
    while (t) cnt ++, t -= t & -t;
    return cnt;
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i ++) {
        cin >> ch;
        a[i] = ch - '0';
        if (a[i] == 0)
            tot[cnt ++] = i - 1;
    }
    tot[cnt] = n;
    for (int i = cnt;i <= n;i ++)
        tot[i] = tot[cnt];
    // for (int i = 0;i <= n;i ++)
    	// cout << tot[i] << " "; cout << "\n";
    for (int i = 1;i <= n;i ++) {
        cin >> s[i];
        if (s[i] == 0) s[i] = -1;
        s[i] = tot[s[i] - 1];
    }
//    for (int i = 1;i <= n;i ++)
//    	cout << s[i] << " ";
//    cout << "\n";
    f[0][0] = 1;
    for (int t = 0;t < (1 << n);t ++) {
        int i = calc(t);
        for (int k = 0;k <= i;k ++) {
//        	cout << t << " " << k << " " << i << " " << f[t][k] << "\n";
            for (int j = 1;j <= n;j ++) {
                if (t & (1 << j - 1)) continue;
                if (s[j] >= i + 1 && a[i + 1] == 1) 
                    f[t | (1 << j - 1)][k + 1] += f[t][k];
                else 
                    f[t | (1 << j - 1)][k] += f[t][k];
            }
        }
    }
    int ans = 0;
    for (int i = m;i <= n;i ++) {
        ans += f[(1 << n) - 1][i];
    }
    cout << ans;
}