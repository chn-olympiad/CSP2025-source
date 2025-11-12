#include<bits/stdc++.h>
using namespace std;
int T, n;
int a[100005][3];
int b[100005];
signed main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> T;
    while(T--){
        cin >> n;
        int num[3] = {0, 0, 0}, ans = 0;
        for(int i = 1; i <= n; i++){
            int p = 0;
            for(int j = 0; j < 3; j++){
                cin >> a[i][j];
                if(a[i][j] > a[i][p])p = j;
            }
            num[p]++, ans += a[i][p];
            b[i] = p;
        }
        int p = 0;
        for(int i = 0; i < 3; i++){
            if(num[i] > num[p])p = i;
        }
        if(num[p] > n / 2){
            vector<int> vec;
            for(int i = 1; i <= n; i++){
                if(b[i] == p)vec.emplace_back(max(a[i][(p+1)%3], a[i][(p+2)%3]) - a[i][p]);
            }
            sort(vec.begin(), vec.end());
            reverse(vec.begin(), vec.end());
            for(int i = 0; i < num[p] - n/2; i++)ans += vec[i];
        }
        cout << ans << '\n';
    }
    return 0;
}