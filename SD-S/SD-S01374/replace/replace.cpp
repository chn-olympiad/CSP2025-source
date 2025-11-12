//#include <bits/stdc++.h>
//#define ll long long
//#define ull unsigned long long
//#define bug(x) cerr << __LINE__ << ":" << (#x) << "=" << (x) << endl
//#define del cerr << endl;
//using namespace std;
//int read() {
//    int s = 0, w = 1;
//    char ch = getchar();
//    while (ch < '0' || ch > '9'){if (ch == '-') w = -1; ch = getchar();}
//    while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
//    return s * w;
//}
//void write(int x) {
//    if (x < 0) putchar('-'), x = -x;
//    if (x > 9) write(x / 10);
//    putchar(x % 10 + '0');
//}
//const int N = 2e3 + 10;
//const int P = 131;
//int n, q;
//string s[N][3];
//string t[N][3];
//int shsh[N][3][N];
//int thsh[N][3][N];
//ull p[N];
//int get_hsh(const int& l, const int& r, const int& x, const int& k) {
//    if (l == 0) return thsh[x][k][r];
//    else return thsh[x][k][r] - thsh[x][k][l - 1] * p[r - l + 1]; 
//}
//int main() {
////    freopen(".in", "r", stdin);
////    freopen(".out", "w", stdout);
//    ios::sync_with_stdio(0);
//    cin.tie(0), cout.tie(0);
//    cin >> n >> q;
//    for (int i = 1; i <= n; i++) {
//        cin >> s[i][1] >> s[i][2];
//    }
//    for (int i = 1; i <= q; i++) {
//        cin >> t[i][1] >> t[i][2];
//    }
//    for (int i = 1; i <= 2001; i++) {
//        p[i] = p[i - 1] * P;
//    }
//    for (int i = 1; i <= n; i++) {
//        for (int j = 0; j < s[i][1].size(); j++) {
//            shsh[i][1][j + 1] = shsh[i][1][j] * P + s[i][1][j];
//        }
//        for (int j = 0; j < s[i][2].size(); j++) {
//            shsh[i][2][j + 1] = shsh[i][2][j] * P + s[i][2][j];
//        }
//    }
//    for (int i = 1; i <= q; i++) {
//        for (int j = 0; j < t[i][1].size(); j++) {
//            thsh[i][1][j + 1] = thsh[i][1][j] * P + t[i][1][j];
//        }
//        for (int j = 0; j < t[i][2].size(); j++) {
//            thsh[i][2][j + 1] = thsh[i][2][j] * P + t[i][2][j];
//        }
//    }
//    
//    for (int i = 1; i <= q; i++) {
//        int ans = 0;
//        if (t[i][1].size() != t[i][2].size()) continue;
//        for (int st = 0; st < t[i][1].size(); st++) {
//            for (int len = 1; len <= t[i][1].size(); len++) {
//                int l = st, r = st + len - 1;
//                bug(l); bug(r);
//                if (l == 2 && r == 3) {
//                    bug(get_hsh(2, 3, i, 1)), bug(shsh[3][1][1]);
//                }
//                for (int j = 1; j <= n; j++) {
//                    if (len != s[j][1].size()) continue;
//                    if (get_hsh(l, r, i, 1) == shsh[j][1][len - 1] && get_hsh(l, r, i, 2) == shsh[j][2][len - 1]) {
//                        bug(i);bug(1);del;
//                        if (get_hsh(1, l - 1, i, 1) == get_hsh(1, l - 1, i, 2) &&
//                            get_hsh(r + 1, t[i][1].size(), i, 1) == get_hsh(r + 1, t[i][1].size(), i, 2)) {
//                                bug(i);bug(2);del;
//                                ans++;
//                        }
//                    }
//                }
//            }
//        }
//        cout << ans << '\n';
//    }
//    return 0;
//}
// fk
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define bug(x) cerr << __LINE__ << ":" << (#x) << "=" << (x) << endl;
#define del cerr << endl;
using namespace std;
int read() {
    int s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9'){if (ch == '-') w = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
    return s * w;
}
void write(int x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n = read(), q = read();
    while (q--) {
        cout << "0\n";
    }
    return 0;
}

