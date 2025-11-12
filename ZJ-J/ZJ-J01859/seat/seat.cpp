#include<bits/stdc++.h>
#define int long long
#define N 105
using namespace std;

int n, m, x, a[N];

signed main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> x;
    for(int i=1; i<n*m; ++i)
        cin >> a[i];
    
    sort(a+1, a+n*m);
    int idx=n*m+1-(lower_bound(a+1, a+n*m, x)-a);

    int col=(idx+n-1)/n;
    int lin=col&1?(idx%n):(n-(idx%n)+1);

    if(!lin) lin=n;
    if(lin==n+1) lin=1;

    cout << col << ' ' << lin << '\n';
    return 0;
}