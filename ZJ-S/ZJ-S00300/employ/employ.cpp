# include <bits/stdc++.h>
using namespace std;
# define int long long
# define rep(i,a,b) for (int i = a; i <= b; i++)
# define pii pair<long,long>

int read(){
    int x = 0, f = 1;
    char ch = getchar_unlocked();
    while(ch < '0' || ch > '9'){
        if (ch == '-') f = -1;
        ch = getchar_unlocked();
    }
    while(ch >= '0' && ch <= '9'){
        x = x * 10 + ch - '0';
        ch = getchar_unlocked();
    }
    return x * f;
}

void write(int x){
    if (x < 0){
        putchar_unlocked('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar_unlocked(x % 10 + '0');
}


const int mod = 998244353;

signed main(){

    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int cnt = 0;
    int n, m;
    n=read(); m = read();
    vector<bool> dif(n);
    vector<pii> p(n);
    string s; cin >> s;
    rep(i,0,n-1){
        dif[i] = s[i] - '0';
    }
    rep(i,0,n-1) {
        p[i].second = read();
        p[i].first = i;
    }
    do{
        int kill = 0, tot = 0;
        rep(i,0,n-1){
            int c = p[i].second;
            if (kill >= c || dif[i] == 0) kill++;
            else tot++;
            if (tot >=m) {cnt = (cnt + 1) % mod;break;}
        }
    }while(next_permutation(p.begin(),p.end()));
    cout << cnt;
    return 0;
}
