#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
const int N = 2e5 + 10, M = 5e6 + 10;
int n, q;
string s[N][3], t1, t2, ss1, ss2, ss3, ss;
int solve1();
int solve2();
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1;i <= n;i ++) {
        cin >> s[i][1] >> s[i][2];
        s[i][1] = s[i][1];
        s[i][2] = s[i][2];
    }
   if (n <= 1000 && q <= 1000 || q == 1) 
		return solve1(), 0;
   for (int i = 1;i <= n;i ++) {
       for (int j = 0;j < s[i][1].size();j ++) {
           if (s[i][1][j] > 'b' || s[i][2][j] > 'b') {
               while (q --) cout << "0\n";
               return 0;
           }
       }
   }
    solve2();
   return 0;
}
int solve1() {
    while (q --) {
        cin >> t1 >> t2; int ans = 0;
        for (int i = 0;i < t1.size();i ++) {
            for (int j = 1;j <= n;j ++) {
                if (i + s[j][1].size() - 1 > t1.size()) continue;
                ss = t1.substr(i, s[j][1].size());
                if (ss != s[j][1]) continue;
                // cout << s[j][1] << " [" << i << ", " << i + s[j][1].size() - 1 << "] " << t1 << "\n"; 
                if (i > 0) ss1 = t1.substr(0, i);
                if (i + s[j][1].size() < t1.size()) ss3 = t1.substr(i + s[j][1].size(), t1.size() - i - s[j][1].size());
                if (i == 0 && i + + s[j][1].size() == t1.size()) {
                	ss2 = s[j][2];
                	// cout << " " << ss2 << "\n";
                	if (ss2 == t2) {
                		ans ++;
					}
				}
				else if (i == 0) {
                    ss2 = s[j][2] + ss3;
                    // cout << " " << ss2 << "\n";
                    if (ss2 == t2) {
                        ans ++;
                    }
                } 
                else if (i + s[j][1].size() == t1.size()) {
                    ss2 = ss1 + s[j][2];
                    // cout << " " << ss2 << "\n";
                    if (ss2 == t2) {
                        ans ++;
                    }
                }
                else {
                    ss2 = ss1 + s[j][2] + ss3;
                    // cout << " " << ss2 << "\n";
                    if (ss2 == t2) {
                        ans ++;
                    }
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
map<int, int> Map;
int p, V;
class Tree {
  public : 
    int t[M];
    void update(int i, int x) {
        i ++;
        for (;i <= V;i += i & -i) t[i] += x;
    }
    int query(int i) {
        int s = 0; i ++;
        for (;i;i -= i & -i) s += t[i];
        return s;
    }
    void clear() {
        for (int i = 0;i <= V;i ++)
            t[i] = 0;
    }
} tr;
vector<pii> a[N];
vector<pair<pii, int>> b[N];
int ans[N];
int solve2() {
    int b1, b2, bb;
    for (int i = 1;i <= n;i ++) {
        b1 = b2 = 0; V = max((int)s[i][1].size(), V);
        for (int j = 0;j < s[i][1].size();j ++) {
            if (s[i][1][j] == 'b') b1 = j;
            if (s[i][2][j] == 'b') b2 = j;
        }
        bb = b1 - b2;
        if (!Map[bb]) Map[bb] = ++ p;
        a[Map[bb]].push_back({min(b1, b2), s[i][1].size() - max(b1, b2)});
    }
    V ++;
    for (int i = 1;i <= q;i ++) {
        cin >> t1 >> t2; b1 = b2 = 0;
        for (int j = 0;j < t1.size();j ++) {
            if (t1[j] == 'b') b1 = j;
            if (t2[j] == 'b') b2 = j;
        }
        bb = b1 - b2;
        if (!Map[bb]) ans[i] = 0; 
        else b[Map[bb]].push_back({{min(b1, b2), t1.size() - max(b1, b2)}, i});
    }
    for (int u = 1;u <= p;u ++) {
        if (b[u].empty()) continue;
        sort(a[u].begin(), a[u].end());
        sort(b[u].begin(), b[u].end());
        int pp = 0; tr.clear();
//        cout << "\n";
//        for (auto pp : a[u]) cout << "[" << pp.first << "," << pp.second << "] "; cout << "\n";
//        for (auto pp : b[u]) cout << "[" << pp.first.first << "," << pp.first.second << "] " << pp.second << " "; cout << "\n";
        for (int i = 0;i < a[u].size();i ++) {
            while (pp != b[u].size() && b[u][pp].first.first < a[u][i].first) {
                ans[b[u][pp].second] = tr.query(b[u][pp].first.second); pp ++;
//                cout << pp << "\n";
            }
            tr.update(a[u][i].second, 1);
        }
//        cout << tr.query(2)  << " " << b[u][pp].first.second << " " << "\n";
        while (pp != b[u].size()) ans[b[u][pp].second] = tr.query(b[u][pp].first.second), pp ++;
    }
//    cout << "\n";
    for (int i = 1;i <= q;i ++)
        cout << ans[i] << "\n";
    return 0;
}