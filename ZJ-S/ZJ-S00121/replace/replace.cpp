#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int P = 10000000000000069, base = 64;
int n, q;
int Hash(string s) {
    int res = 0;
    for(int i = 0; s[i]; i ++) {
        res = res * base + s[i] - 'a';
        res %= P;
    }
    return res;
}
map<int, int> cnt;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; i ++) {
        string s1, s2;
        cin >> s1 >> s2;
        cnt[Hash(s1 + s2)] ++;
    }
    for(int i = 1; i <= q; i ++) {
        string s1, s2;
        cin >> s1 >> s2;
        if(s1.size() != s2.size()) {
            cout << "0\n";
            continue;
        }
        int st = -1, ed = -1;
        for(int i = 0; s1[i]; i ++) {
            if(s1[i] != s2[i]) {
                if(st == -1) {
                    st = i;
                }
                ed = i;
            }
        }
        int res = 0;
        for(int l = 0; s1[l]; l ++) {
            string ss1 = "", ss2 = "";
            for(int r = l; s1[r]; r ++) {
                ss1 += s1[r];
                ss2 += s2[r];
                if(l <= st && r >= ed) {
                    res += cnt[Hash(ss1 + ss2)];
                }
            }
        }
        cout << res << "\n";
    }
    return 0;
}

/*

下面是我写挂的代码。纪念一下。

*/

// #include<bits/stdc++.h>
// using namespace std;
// constexpr int N = 5000005;
// int toint(char a, char b) {
//     return 26 * (a - 'a') + b - 'a';
// }
// struct AC {
//     struct Nxt {
//         int v, vl;
//     } ;
//     vector<Nxt> nxt[N];
//     int c[N];
//     int val[N];
//     int deep[N];
//     int cnt;
//     int fail[N];
//     int find_nxt(int u, int val) {
//         for(Nxt i : nxt[u]) {
//             if(i.vl == val) {
//                 return i.v;
//             }
//         }
//         return 0;
//     }
//     AC() {
//         cnt = 0;
//     }
//     int newnode() {
//         cnt += 1;
//         return cnt;
//     }
//     void insert(string s1, string s2, int len) {
//         int cur = 0;
//         for(int i = 0; i < len; i ++) {
//             int val = toint(s1[i], s2[i]);
//             int v = find_nxt(cur, val);
//             if(v == 0) {
//                 v = newnode();
//                 c[v] = val;
//                 nxt[cur].push_back({v, val});
//                 deep[v] = deep[cur] + 1;
//             }
//             cur = v;
//         }
//         val[cur] += 1;
//     }
//     void build_dfs(int u, int F) {
//         val[u] += val[F];
//         int fail_fa = fail[F];
//         if(fail_fa == F) {
//             fail[u] = 0;
//         } else {
//             int nxt_node = find_nxt(fail_fa, c[u]);
//             if(nxt_node) {
//                 fail[u] = nxt_node;
//             } else {
//                 fail[u] = fail[fail_fa];
//             }
//         }
//         for(Nxt i : nxt[u]) {
//             build_dfs(i.v, u);
//         }
//         return ;
//     }
//     void build() {
//         fail[0] = 0;
//         for(Nxt i : nxt[0]) {
//             build_dfs(i.v, 0);
//         }
//     }
// } ac;
// int n, q;
// int dl[N];
// signed main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     freopen("replace1.in", "r", stdin);
//     freopen("replace.out", "w", stdout);
//     cin >> n >> q;
//     for(int i = 1; i <= n; i ++) {
//         string a, b;
//         cin >> a >> b;
//         int len = a.size();
//         ac.insert(a, b, len);
//     }
//     ac.build();
//     for(int i = 1; i <= q; i ++) {
//         string a, b;
//         cin >> a >> b;
//         if(a.size() != b.size()) {
//             cout << "0\n";
//             continue;
//         }
//         int st = -1, ed = -1;
//         for(int i = 0; a[i]; i ++) {
//             if(a[i] != b[i]) {
//                 if(st == -1) st = i;
//                 ed = i;
//             }
//         }
//         int cur = 0;
//         for(int i = 0; i < ed; i ++) {
//             dl[i] = 0;
//             int nxt = ac.find_nxt(cur, toint(a[i], b[i]));
//             if(nxt) {
//                 cur = nxt;
//             } else {
//                 if(cur == ac.fail[cur]) {
//                     cur = 0;
//                 } else {
//                     cur = ac.fail[cur];
//                     i --;
//                 }
//             }
//         }
//         while(cur) {
//             int l = ed - ac.deep[cur];
//             dl[l] = ac.val[cur];
//             cur = ac.fail[cur];
//         }
//         cur = 0;
//         int res = 0;
//         for(int i = 0; a[i]; i ++) {
//             int nxt = ac.find_nxt(cur, toint(a[i], b[i]));
//             if(nxt) {
//                 cur = nxt;
//             } else {
//                 if(cur == ac.fail[cur]) {
//                     cur = 0;
//                 } else {
//                     if(i - 1 >= ed) {
//                         int l = i - ac.deep[cur];
//                         if(l > st) break;
//                         cout << ac.val[cur] << " " << dl[l] << "\n"; 
//                         res += ac.val[cur];
//                         res -= dl[l];
//                     }
//                     cur = ac.fail[cur];
//                     i --;
//                 }
//             }
//         }
//         int l = a.size() - ac.deep[cur]; 
//         if(l <= st) {
//             cout << ac.val[cur] << " " << dl[l] << "\n"; 
//             res += ac.val[cur];
//             res -= dl[l];
//         }
//         cout << res << "\n";
//     }
//     cerr << clock() * 1.0 / CLOCKS_PER_SEC << "\n";
//     return 0;
// }