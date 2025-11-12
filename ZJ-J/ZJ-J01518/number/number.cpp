#include<bits/stdc++.h>
using namespace std;

string s;
int len, a[1000005], cnt = 0;

int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    len = s.size();
    s = " " + s;
    for(int i = 1;i <= len;i++){
        if(s[i] >= '0' && s[i] <= '9') {
            cnt++;
            a[cnt] = int(s[i] - '0');
        }
    }
    sort(a + 1, a + cnt + 1);
    for(int i = cnt;i >= 1;i--) cout<<a[i];
    cout<<'\n';
    return 0;
}