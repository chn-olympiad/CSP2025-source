#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[505],b[505],t[505],idx[505];
int MOD = 998244353,ans;

bool check(){
    int cnt = 0;
    for (int i = 1;i<=n;i++){
        if (a[i] == 0 || b[idx[i]] <=cnt){
            cnt++;
        }
    }
    return (m<=(n-cnt));
}

void dg(int c){
    if (c == n+1){
        if (check())ans++;
        ans%=MOD;
        return ;
    }
    for (int i = 1;i<=n;i++){
        if (t[i])continue;
        idx[c] = i;
        t[i] ++;
        dg(c+1);
        t[i]--;
    }
}

int main(){

    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    cin>>n>>m;

    string s;
    cin>>s;
    for (int i = 1;i<=n;i++){
        a[i] = s[i-1]-'0';
    }
    for (int i = 1;i<=n;i++){
        cin>>b[i];
    }

    if (n<=18){
        dg(1);

        cout<<ans;

        return 0;
    }

    cout<<0;

    return 0;
}
