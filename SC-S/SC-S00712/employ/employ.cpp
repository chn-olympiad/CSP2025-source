#include <cstdio>
#include <iostream>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,ans = 1;
    cin >> n >> m;
    long long s;
    cin >> s;
    int c[n];
    for (int i = 0;i<n;i++){
        cin >> c[i];
    }
    for (int i =1;i<=n;i++){
        ans *= i;
    }
    cout << ans%998244353;
    return 0;
}