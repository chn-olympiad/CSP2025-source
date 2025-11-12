#include<bits/stdc++.h>
using namespace std;
int m = 998244353;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int s,n,ans;
    cin >> s,n;
    for(int i = 1;i <= s * n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= s;i++)
        for(int j = 1;j <= s * n;j++)
            if(a[i] < a[j])
    for(int i = 1;i <= s * n;i++)
        cout << a[i] << ' ';
    return 0;
}
