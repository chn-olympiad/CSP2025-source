#include<bits/stdc++.h>

using namespace std;

int main() {
    freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int a[n * m];
    for (int i = 0; i < n * m; i ++) {
        cin >> a[i];
    }
    int t = a[0];
    sort(a, a + n * m);
    int i = 0;
    // for (int i = 0; i < n * m; i ++) cout << a[i] << " "; cout << endl;
    
    for(; i < n * m; i ++) {
        if (a[i] == t) break;
    }
    // cout << i << endl;
    i = m * n - i;
    int c = i / n + (i % n != 0), r = i % m;
    if (!r) r = m;
    if (!(c % 2)) r = m - r + 1; 
    cout << c << " " << r;
}
/*

2 2
99 100 97 98
2 2
98 99 100 97
3 3
94 95 96 97 98 99 100 93 92
*/