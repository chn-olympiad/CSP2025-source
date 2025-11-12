#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m, k, ans;
int a[10004][100006], m1, n1, q1;
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    for (int i = 0 ; i < m; i ++){
        cin >> n1 >> m1 >> q1;
        ans += q1;
    }
    cout << q1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

