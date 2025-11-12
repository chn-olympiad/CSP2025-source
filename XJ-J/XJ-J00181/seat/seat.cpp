#include <iostream>
#include <algorithm>
//haihaihai_Long_Live_the_People's_Republic_of_China!!!
using std::cin;
using std::cout;
int n, m, s, a[105];
signed main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++)
        cin >> a[i];
    s = a[1];
    std::sort(a + 1, a + n * m + 1);
    int add = std::lower_bound(a + 1, a + n * m + 1, s) - a;
    add = n * m - add + 1;
    int x = (add + n - 1) / n, y = add % n;
    cout << x << ' ';
    if (x % 2)
        cout << y;
    else 
        cout << n - y + 1;
}