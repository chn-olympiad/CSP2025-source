#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 2e5 + 9;
struct IO {
    IO () {
        freopen("replace.in", "r", stdin);
        freopen("replace.out", "w", stdout);
    }
    ~IO () {
        fclose(stdin);
        fclose(stdout);
    }
} io;
int n, q;
int no[N];
string s[N][2], t1, t2;
int main () {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
        cin >> s[i][0] >> s[i][1];
        int len = s[i][0].size();
        for (int j = 0; j < len; j++)
            no[i] += s[i][0][j] != s[i][1][j];
    }
    while (q--) {
        cin >> t1 >> t2;
        int ans = 0, res = 0;
        int len = t1.size();
        for (int i = 0; i < len; i++)
            res += t1[i] != t2[i];
        for (int i = 1; i <= n; i++) {
            if (res != no[i]) continue;
            int lx = s[i][0].size();
            for (int j = 0; j < len; j++)
                if (t1[j] == s[i][0][0] && t2[j] == s[i][1][0]) {
                    bool f = true;
                    for (int k = 0; k < lx; k++)
                        if (t1[j + k] != s[i][0][k] || t2[j + k] != s[i][1][k]) {
                            f = 0;
                            break;
                        }
                    ans += f;
                    // if (f) printf("Yes %d %d\n", i, j);
                }
        }
        printf("%d\n", ans);
    }
    return 0;
}