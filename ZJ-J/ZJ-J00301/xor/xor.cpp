#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 7;
const int M = 5005; 
int n, m, cnt = 0, ans1 = 0, ans2 = 0, a[N], g = 0;
bool flag[N];
bool f = 0;
signed main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] > 1) f = 1;
    }
    if(!f){
        int re = 0;
        if(m >= 2){
            cout << 0 << endl;
            return 0;
        }
        if(m == 1){
            for(int i = 1; i <= n; i++){
                if(a[i] == 1) re++;
            }
            cout << re << endl;
            return 0;
        }
        for(int i = 1; i <= n; i++){
            if(flag[i]) continue;
            if(a[i] == 0) re++;
            if(a[i] == 1){
                if(a[i + 1] == 1){
                    re++;
                    flag[i] = 1;
                    flag[i + 1] = 1;
                }
            }    
        }
        cout << re << endl;
        return 0;
    }
    for(int i = 1; i <= n; i++) 
    {
        for(int k = 1; k <= n; k++){
            bool u = 0;
            if(flag[k]) continue;
            cnt = 0;
            for(int j = 1; j <= i; j++){
                if(flag[k + j - 1]){
                    break;
                    u = 1;
                }
                cnt = cnt xor a[k + j - 1]; 
            }
            if(u) continue;
            if(cnt == m){
                ans1++;
                for(int p = 1; p <= i; p++){
                    flag[k + p - 1] = 1; 
                }
            }
            // cout << cnt << " " << endl;
        }
        // for(int f = 1; f <= n; f++){
        //     if(flag[f]) cout << a[f] << " " << f << "              ";
        // }
        // cout<< endl;
    }
    cout << ans1 << endl;
    return 0;
}