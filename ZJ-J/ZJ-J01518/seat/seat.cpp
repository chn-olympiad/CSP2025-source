#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], res, pos, p, q, r, c;

int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n * m;i++) cin >> a[i];
    res = a[1];
    sort(a + 1, a + n * m + 1);
    for(int i = n * m;i >= 1;i--){
        if(a[i] == res){
            pos = n * m - i + 1;
            break;
        }
    }
    p = (pos - 1) / n;
    q = pos % n;
    c = p + 1;
    if(p % 2 == 0){
        if(q == 0) r = n;
        else r = q;
    }else{
        if(q == 0) r = 1;
        else r = n - q + 1;
    }
    cout<<c<<' '<<r<<'\n';
    return 0;
}