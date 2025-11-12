#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
struct dat{ string a, b; } s[N];
int n, q;
bool cmp(dat a, dat b){
    if (a.a != b.a) return a.a < b.a;
    return a.b < b.b;
};
bool f(string str, string g){
    int l = 1, r = n, m;
    while (l <= r){
        m = l + r >> 1;
        if (s[m].a == str) {
            for (int i = m;s[i].a == str;i --){
                if (s[m].b == g) return true;
            }
            for (int i = m;s[i].a == str;i ++){
                if (s[m].b == g) return true;
            }
            return false;
        }
        else if (s[m].a < str){
            l = m + 1;
        }
        else{
            r = m - 1;
        }
    }
    return false;
}
int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 1;i <= n;i ++) cin >> s[i].a >> s[i].b;
    sort(s + 1, s + 1 + n, cmp);
    /*
    for (int i = 1;i <= n;i ++){
        cout << s[i].a << ' ' << s[i].b << '\n';
    }*/
    for (int i = 1;i <= q;i ++){
        string s1, s2;
        int ans = 0;
        cin >> s1 >> s2;
        if (s1.size() != s2.size()){
            cout << 0 << '\n';
            continue;
        }
        int cnt1 = 0, cnt2 = 0;
        for (int i = 1;i < s1.size();i ++){
            if (s1[i] != s2[i]) cnt2 ++;
            if (s1[i] != s2[i] && s1[i - 1] == s2[i - 1]){
                cnt1 ++;
                if (cnt1 == 2) break;
            }
        }
        if (s1[0] != s2[0]) cnt2 ++;
        if (cnt1 > 1){
            cout << 0 << '\n';
            continue;
        }
        for (int i = 0;i < s1.size();i ++){
            string tmp1 = "", tmp2 = "";
            for (int j = i;j < s2.size();j ++){
                tmp1 += s1[j];
                tmp2 += s2[j];
                if (f(tmp1, tmp2)){
                    if (cnt2 > tmp2.size()){
                        ans --;
                    }
                    ans ++;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

---------------------
2
0
*/