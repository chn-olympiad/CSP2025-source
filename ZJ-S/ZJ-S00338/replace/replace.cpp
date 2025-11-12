#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int n, q, now;
bool flagg[N];
string k1, k2;
struct node{
    string s1, s2;
    int cnt;
};
map< int, node> mp;
// void solve(){
//     for(int i = 1; i <= n; i++){
//         for(int j = 1; j <= n; j++){
//             if(i == j) continue;
//             if(mp[i].s1.find(mp[j].s1) <= mp[i].s1.size() && mp[i].s1.find(mp[j].s1) == mp[i].s2.find(mp[j].s2)) mp[i].cnt++;
//         } 
//     }
//     for(int i = 1; i <= n; i++){
//         for(int j = i; j <= n; j++){
//             if(mp[i].cnt < mp[j].cnt){
//                 node x = mp[i];
//                 mp[i] = mp[j];
//                 mp[j] = x;
//             }
//         }
//     }
//     return;
// }

int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> mp[i].s1 >> mp[i].s2;
        mp[i].cnt = 1;
    }
    // solve();
    // for(int i = 1; i <= n; i++){
    //     cout << mp[i].s1 << " " << mp[i].s2 << " " << mp[i].cnt  << endl;
    // }
    while(q--){
        memset(flagg, 0, sizeof flagg);
        int ans = 0;
        string ss1, ss2;
        cin >> ss1 >> ss2;
        if(ss1.size() != ss2.size()){
            cout << 0 << endl;
            continue;
        }
        bool ppp = 0;
        for(int i = 1; i <= n; i++){
            if(ss1.find(mp[i].s1) < ss1.size() && ss1.find(mp[i].s1) == ss2.find(mp[i].s2)){
                int nowplace = ss1.find(mp[i].s1);
                // cout << nowplace +  << endl;
                string t1 = ss1;
                for(int j = nowplace; j <= nowplace + mp[i].s1.size() - 1; j++){
                    t1[j] = mp[i].s2[j - nowplace];
                    // cout << t1[j] << " ";
                }
                // cout << endl;
                // cout << t1 << endl;
                if(t1 == ss2){
                    ans += 1;
                }
                // if(t1 == ss2 && (!flagg[nowplace] || !flagg[nowplace + mp[i].s1.size() - 1])){
                //     for(int j = nowplace; j <= nowplace + mp[i].s1.size() - 1; j++) flagg[j] = 1;
                //     ans += mp[i].cnt;
                // }
            }
        }
        cout << ans << endl;
    }
    return 0;
}