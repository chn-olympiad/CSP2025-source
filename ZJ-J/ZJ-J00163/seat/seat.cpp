#include <bits/stdc++.h>
using namespace std;
long long n,m,a[110],cnt;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin >> a[i];
        if(a[i]>a[1]){
            cnt++;
        }
    }
    cnt++;
    long long r = (cnt - 1) / n + 1,c;
    if(r%2==1){
        c = (cnt - 1) % n + 1;
    }else{
        c = n-((cnt - 1) % n + 1)+1;
    }
    cout << r << ' ' << c << '\n';
    return 0;
}
/*
AK 自动机   rp++
CCF Orz
*/