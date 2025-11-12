#include <bits/stdc++.h>

using namespace std;



int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    int t = n * m;
    int a[t + 10];
    int R;
    int x;
    int cnew;
    cin >> R;
    a[1] = R;
    for (int i = 2; i <= t; i++) {
        cin >> a[i];
    }
    sort(begin(a), end(a));
    int r = ;
    int c = R % n;
    if ( r % 2 == 0 ) {
        x = n - c;
        cnew = n - x;
        c = cnew;
    }
    cout << c << " " << r << endl;
 return 0;
}
