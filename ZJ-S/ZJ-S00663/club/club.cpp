#include <bits/stdc++.h>

#define A 0
#define B 1
#define C 2

using namespace std;

int t;
int n;
int ans = 0;

int a[100010];
int b[100010];
int c[100010];

int f[100010];

void dfs (int nscr, int nstu, int sa, int sb, int sc) {
    if (sa + sb + sc == n) {
        ans = max (nscr, ans);
        // return nscr;
    }

    // int nnscr = 0;

    // if (f[nstu] != -1) {
    //     nnscr = nscr + f[nstu];
    //     ans = max (nscr, ans);
    //     return nnscr;
    // }

    if (sa + 1 <= n / 2) {
        // int nnnscr;
        dfs (nscr + a[nstu], nstu + 1, sa + 1, sb, sc);
        // nnscr = max (nnnscr, nnscr);
    }
    if (sb + 1 <= n / 2) {
        // int nnnscr;
        dfs (nscr + b[nstu], nstu + 1, sa, sb + 1, sc);
        // nnscr = max (nnnscr, nnscr);
    }
    if (sc + 1 <= n / 2) {
        // int nnnscr;
        dfs (nscr + c[nstu], nstu + 1, sa, sb, sc + 1);
        // nnscr = max (nnnscr, nnscr);
    }
    // f[nstu] = nnscr;

    // return nnscr;
}

int main () {
    freopen ("club.in", "r", stdin);
    freopen ("club.out", "w", stdout);

    cin >> t;
    while (t--) {
        ans = 0;

        cin >> n;

        if (n == 2) {
            int aa1, bb1, cc1, aa2, bb2, cc2;
            cin  >> aa1 >> bb1 >> cc1;
            cin  >> aa2 >> bb2 >> cc2;

            int mm1, mm2;
            mm1 = max (aa1, max (bb1, cc1));
            mm2 = max (aa2, max (bb2, cc2));

            if (mm1 == aa1 && mm2 == aa2) {
                if (mm1 > mm2) {
                    ans += mm1;
                    ans += max (bb2, cc2);
                } else {
                    ans += mm2;
                    ans += max (bb1, cc1);
                }
            } else if (mm1 == bb1 && mm2 == bb2) {
                if (mm1 > mm2) {
                    ans += mm1;
                    ans += max (aa2, cc2);
                } else {
                    ans += mm2;
                    ans += max (aa1, cc1);
                }
            } else if (mm1 == cc1 && mm2 == cc2) {
                if (mm1 > mm2) {
                    ans += mm1;
                    ans += max (aa2, bb2);
                } else {
                    ans += mm2;
                    ans += max (aa1, bb1);
                }
            } else {
                ans = mm1 + mm2;
            }

            cout << ans << endl;
            continue;
        }

        for (int i = 1; i <= n; ++i) {
            int aa, bb, cc;
            cin >> a[i] >> b[i] >> c[i];
        }

        // for (int i = 1; i <= n; ++i) {
        //     f[i] = -1;
        // }

        dfs (0, 1, 0, 0, 0);

        cout << ans << endl;
    }

    

    fclose (stdin);
    fclose (stdout);
    return 0;
}