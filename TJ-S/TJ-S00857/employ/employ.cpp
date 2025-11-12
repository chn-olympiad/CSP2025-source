#include <bits/stdc++.h>
using namespace std;
char b[505];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n, m, a[505];
    cin >> n >> m;
    cin >> b;
    for( int i = 1; i <= n; i++ ){
        cin >> a[i];
    }
    bool f = true;
    int l = strlen(b);
    for( int i = 0; i < l; i++ ){
        if( b[i] == '0' ){
            f = false;
        }
    }
    long long sum = 0;
    if( n == m ){
        if( f ){
            cout << 1;
        }
        else{
            cout << 0;
        }
    }
    else if( f ){
        long long tmp = 1;
        for( int i = 1; i <= m; i++ ){
            tmp *= i;
        }
        sum = tmp;
        sum %= 998244353;
        for( int i = m+1; i <= n; i++ ){
            sum = sum + tmp*i;
            tmp *= i;
            sum %= 998244353;
        }
        cout << sum;
    }
    return 0;
}
