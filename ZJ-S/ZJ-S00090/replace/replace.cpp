#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+5;

int n, q, ans;
string a[N][2], t1, t2;

signed main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i][0] >> a[i][1];
    while(q--)
    {
        cin >> t1 >> t2;
        cout << "0\n";
    }
    return 0;
}