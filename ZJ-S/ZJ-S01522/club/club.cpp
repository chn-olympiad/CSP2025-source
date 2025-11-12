#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct www{
    int a, b, c;
} club[N];
int t, n,ans;
vector<int> a,b,c;
void dfs(int l){
    if(l>n){
        int sum = 0;
        for(auto i:a){
            sum += club[i].a;
        }
        for(auto i:b){
            sum += club[i].b;
        }
        for(auto i:c){
            sum += club[i].c;
        }
        ans = max(ans, sum);
        return;
    }
    if(a.size()<n/2){
        a.push_back(l);
        dfs(l + 1);
        a.pop_back();
    }
    if(b.size()<n/2){
        b.push_back(l);
        dfs(l + 1);
        b.pop_back();
    }
    if(c.size()<n/2){
        c.push_back(l);
        dfs(l + 1);
        c.pop_back();
    } 
}
bool cmp(www u,www v){
    return u.a > v.a;
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        ans = 0;
        a.clear();
        b.clear();
        c.clear();
        cin >> n;
        for(int i=1;i<=n;i++){
            cin >> club[i].a >> club[i].b >> club[i].c;
        }
        if(n<=30){
            dfs(1);
        }else{
            sort(club + 1, club + n + 1, cmp);
            for (int i = 1; i <= n / 2;i++){
                ans += club[i].a;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
