#include<bits/stdc++.h>
using namespace std;
#define ll long long

inline ll read(){
    ll f = 1, res = 0;
    char c = getchar();
    while(c > '9' || c < '0'){
        if(c == '-')f = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9'){
        res = res * 10 + c - '0';
        c = getchar();
    }
    return f * res;
}

const int N = 100010;

ll cnt[5];

signed main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ll t = read();
    while(t --){
        memset(cnt, 0, sizeof cnt);
        ll n = read();
        priority_queue<ll, vector<ll>, greater<ll>>q1, q2, q3;
        ll ans = 0;


        for(int i = 1; i <= n; i ++){
            ll a = read(), b = read(), c = read();
            ll maxx, se_maxx;

            if(a >= b && a >= c){
                maxx = a;
                se_maxx = max(b, c);
                cnt[1] ++;
                ans += maxx;
                q1. push(maxx - se_maxx);
            }
            else if(b >= a && b >= c){
                maxx = b;
                se_maxx = max(a, c);
                cnt[2] ++;
                ans += maxx;
                q2. push(maxx - se_maxx);
            }
            else if(c >= a && c >= b){
                maxx = c;
                se_maxx = max(a, b);
                cnt[3] ++;
                ans += maxx;
                q3. push(maxx - se_maxx);
            }
        }


        if(cnt[1] > n / 2){
            ll j = cnt[1] - (n / 2);
            while(j --){
                ll mid = q1. top();
                q1. pop();
                ans -= mid;
            }
        }
        else if(cnt[2] > n / 2){
            ll j = cnt[2] - (n / 2);
            while(j --){
                ll mid = q2. top();
                q2. pop();
                ans -= mid;
            }
        }
        else if(cnt[3] > n / 2){
            ll j = cnt[3] - (n / 2);
            while(j --){
                ll mid = q3. top();
                q3. pop();
                ans -= mid;
            }
        }


        cout << ans << endl;
    }
    return 0;
}