#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[50010];
int lp[50010], rp[50010];
int lst[50010];
int pn = 0;
int ans = 0;

void dfs (int pppt, int ns) {
    int npppt;
    npppt = pppt + 1;
    while (pn >= npppt) {
        if (lp[npppt] > rp[pppt]) break;
        ++npppt;
    }

    if (npppt == pn) {
        if (lp[npppt] > rp[pppt]) ans = max (ans, ns + 1);
        else ans = max (ans, ns);
        return;
    }

    dfs (npppt, ns + 1);
}

int main () {
    freopen ("xor.in", "r", stdin);
    freopen ("xor.out", "w", stdout);
    
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
        int nans = a[i];

        if (nans == k) {
            ++ pn;
            lp[pn] = i;
            rp[pn] = i;
            continue;
        }

        for (int j = i + 1; j <= n; ++j) {
            nans ^= a[j];
            
            if (nans == k) { 
                ++ pn;
                lp[pn] = i;
                rp[pn] = j;
                break;
            }
        }
    }

    cout << pn;

    // dfs (0, 0);

    // cout << ans << endl;

    fclose (stdin);
    fclose (stdout);
    return 0;
}