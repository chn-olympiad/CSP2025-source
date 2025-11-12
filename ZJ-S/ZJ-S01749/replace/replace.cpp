#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn = 2e5 + 10;
unordered_map<string , vector<string>> mp;
int ans = 0;
void dfs(string u , string t)
{
    if(u == t)
    {
        ++ans;
        return;
    }
    for(auto it : mp)
    {
        int p = -1;
        int l = u.length();
        while(u.find(u.begin() + p + 1 , u.end() , it.first) != string::npos)
        {
            for(string v : it.second)
            {
                string nu = u.substr(0 , p - 1) + v + u.substr(p + it.first.length());
                dfs(nu , t);
            }
        }
    }
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n , q;
    cin >> n >> q;
    string s1 , s2;
    for(int i = 1; i <= n; ++i)
    {
        cin >> s1 >> s2;
        mp[s1].push_back(s2);
        mp[s2].push_back(s1);
    }
    string s , t;
    while(q--)
    {
        ans = 0;
        cin >> s >> t;
        dfs(s , t);
        cout << ans << "\n";
    }
    return 0;
}
