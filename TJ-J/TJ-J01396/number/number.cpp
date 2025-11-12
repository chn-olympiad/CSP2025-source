#include <bits/stdc++.h>
using namespace std;
const int m = 1e6+5;
char a[m];
int b[m], cnt = 0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> a;
    int l = strlen(a);
    for( int i = 0; i < l; i++ ){
        if( '0' <= a[i] && a[i] <= '9' ){
            b[cnt++] = a[i] - '0';
        }
    }
    sort(b, b+cnt);
    if( b[cnt-1] == 0 ){
        cout << 0;
        return 0;
    }
    for( int i = cnt-1; i >= 0; i-- ){
        cout << b[i];
    }
    return 0;
}
