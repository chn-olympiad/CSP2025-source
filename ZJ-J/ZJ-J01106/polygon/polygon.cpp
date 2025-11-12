#include <bits/stdc++.h>
using namespace std;
constexpr int MOD = 998244353;
vector<int> num;
int n, ans;
void dfs(int x, int sum, int mx, int cnt){
    if(x==n){
        if(cnt<3)return;
        if(sum<=mx*2)return;
        ans++;
        if(ans==MOD){
            ans = 0;
        }
        return;
    }

    // in
    dfs(x+1, sum+num[x], max(num[x], mx), cnt+1);

    // out
    dfs(x+1, sum, mx, cnt);
}
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    bool flagAllOne = true;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        num.push_back(x);
        if(x!=1){
            flagAllOne = false;
        }
    }
    if(flagAllOne){
        long long ans = 0;
        for(int i=3;i<=n;i++){
            for(int j=n;j>=n-i+1;j--){
                ans=(ans*j)%MOD;
            }
        }
        cout<<ans<<endl;
        return 0;
    }
    sort(num.begin(), num.end());
    dfs(0, 0, 0, 0);
    cout<<ans<<endl;
}
// 有 1, 2 ,3 ,4 组成一个多边形，则必定有 1 2 3 4 (n, 0<n<10)
// 尝试找到一个合法的三角形，并不断加边，同时减去可能重复的图形