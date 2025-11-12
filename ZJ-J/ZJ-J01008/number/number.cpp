#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int cnt = 0;
    int len = s.size();
    for(int i = 0;i < len;i++){
        if(s[i] >= '0' && s[i] <= '9'){
            a[++cnt] = int(s[i] - '0');
        }
    }
    sort(a + 1,a + cnt + 1,greater<int>());
    for(int i = 1;i <= cnt;i++){
        cout << a[i];
    }





    return 0;
}
