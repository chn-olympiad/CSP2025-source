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

const int N = 200010;


struct ii{
    string s1, s2;
    ll len;
};

ii ave[30][200010];
ll idx[30];


struct iii{
    ll to_l, to_r;
};

unordered_map<ll, vector<iii>>ma;

signed main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ll n = read(), q = read();
    if(n > 10000 || q > 10000){
        for(int i = 1; i <= n; i ++){
            string s1, s2;
            cin >> s1 >> s2;
            ll len = s1. size();
            s1 = ' ' + s1, s2 = ' ' + s2;
            ll mov, to_l_1, to_r_1, to_l_2;
            for(int i = 1; i <= len; i ++){
                if(s1[i] == 'b'){
                    to_l_1 = i;
                    to_r_1 = len - i + 1;
                }
                if(s2[i] == 'b'){
                    to_l_2 = i;
                }
            }
            mov = to_l_2 - to_l_1;//right
            ma[mov]. push_back({to_l_1, to_r_1});
            // cout << mov << ' ' << to_l_1 << ' ' << to_r_1 << endl;
        }
        while(q --){
            string s1, s2;
            cin >> s1 >> s2;
            ll ans = 0;
            if(s1. size() != s2. size()){
                cout << 0 << endl;
                continue;
            }
            ll len = s1. size();
            s1 = ' ' + s1, s2 = ' ' + s2;
            ll mov, to_l_1, to_r_1, to_l_2;
            for(int i = 1; i <= len; i ++){
                if(s1[i] == 'b'){
                    to_l_1 = i;
                    to_r_1 = len - i + 1;
                }
                if(s2[i] == 'b'){
                    to_l_2 = i;
                }
            }
            mov = to_l_2 - to_l_1;
            for(auto it = ma[mov]. begin(); it != ma[mov]. end(); it ++){
                iii mid = *it;
                if(to_l_1 >= mid. to_l && to_r_1 >= mid. to_r){
                    ans ++;
                }
            }
            cout << ans << endl;
        }
        return 0;
    }
    for(int i = 1; i <= n; i ++){
        string s1, s2;
        cin >> s1 >> s2;
        ll len = s1. size();
        ii mid = {s1, s2, len};
        ll num = (ll)(s1[0] - 'a');
        ave[num][++ idx[num]] = mid;
    }
    while(q --){
        string q1, q2;
        cin >> q1 >> q2;
        if(q1. size() != q2. size()){
            cout << 0 << endl;
            continue;
        }
        ll ans = 0;

        ll q_len = q1. size();
        for(int i = 0; i < q_len; i ++){
            for(int j = 1; j <= idx[(ll)(q1[i] - 'a')]; j ++){
                ii mid = ave[(ll)(q1[i] - 'a')][j];
                if(i + mid. len > q_len)continue;
                if(q1. substr(i, mid. len) == mid. s1 && q2. substr(i, mid. len) == mid. s2){
                    if(q1. substr(i + mid. len) != q2. substr(i + mid. len) || q1. substr(0, i) != q2. substr(0, i))continue;
                    ans ++;
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}