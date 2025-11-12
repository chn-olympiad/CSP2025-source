#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 1e6 + 7;
int T, n;
struct node{
    int a, b, c, fir, sec, thi, cha, fs, sc;
};
node happ[N];
deque < node > q[5];

bool cmp(node x, node y){
    return x.cha < y.cha;
}

void solve(){
    int ans = 0;
    sort(happ + 1, happ + n + 1, cmp);
    for(int i = 1; i <= n; i++){
        if(q[happ[i].fs].size() < n / 2) q[happ[i].fs].push_back(happ[i]);
        else{
            node x = q[happ[i].fs].front();
            q[x.sc].push_back(x);
            q[happ[i].fs].pop_front();
            q[happ[i].fs].push_back(happ[i]);
        }
    }
    while(!q[1].empty()){
        node x = q[1].front();
        if(x.fs == 1) ans += x.fir;
        else ans += x.sec;
        q[1].pop_front();    
        // cout << ans << " ";
    }
    // cout << 1 <<  endl;
    while(!q[2].empty()){
        node x = q[2].front();
        if(x.fs == 2) ans += x.fir;
        else ans += x.sec;
        q[2].pop_front();    
        // cout << ans << " ";
    }
    // cout << 2 << endl;
    while(!q[3].empty()){
        node x = q[3].front();
        if(x.fs == 3) ans += x.fir;
        else ans += x.sec;
        q[3].pop_front(); 
        // cout << ans << " ";   
    }
    // cout << 3 << endl;
    cout << ans << endl;
    return;
}

signed main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> T;
    while(T--){
        memset(happ, 0, sizeof happ);
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> happ[i].a >> happ[i].b >> happ[i].c;
            if(happ[i].a >= happ[i].b && happ[i].a >= happ[i].c){
                happ[i].fir = happ[i].a;
                happ[i].fs = 1;
                if(happ[i].b >= happ[i].c){
                    happ[i].sec = happ[i].b;
                    happ[i].sc = 2;
                } 
                else{
                    happ[i].sec = happ[i].c;
                    happ[i].sc = 3;
                }
                happ[i].cha = happ[i].fir - happ[i].sec;
                continue;
            }
            if(happ[i].b >= happ[i].a && happ[i].b >= happ[i].c){
                happ[i].fir = happ[i].b;
                happ[i].fs = 2;
                if(happ[i].a >= happ[i].c){
                    happ[i].sec = happ[i].a;
                    happ[i].sc = 1;
                } 
                else{
                    happ[i].sec = happ[i].c;
                    happ[i].sc = 3;
                }
                happ[i].cha = happ[i].fir - happ[i].sec;
                continue;
            }
            if(happ[i].c >= happ[i].b && happ[i].a <= happ[i].c){
                happ[i].fir = happ[i].c;
                happ[i].fs = 3;
                if(happ[i].b >= happ[i].a){
                    happ[i].sec = happ[i].b;
                    happ[i].sc = 2;
                } 
                else{
                    happ[i].sec = happ[i].a;
                    happ[i].sc = 1;
                }
                happ[i].cha = happ[i].fir - happ[i].sec;
                continue;
            }
        }
        solve();
        // cout << endl << endl;
    }
    return 0;
}