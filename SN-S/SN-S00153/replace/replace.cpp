#include <bits/stdc++.h>
using namespace std;
using i128 = __int128;
using ll = long long;
const int N = 2e5 + 5,M = 5e6 + 5;
const ll mod = (1ll << 61) - 1,B = 120519;
int n,m,p[N],len[N],con[N]; string s,t; 
vector<ll> ln[N],h1[N],h2[N]; vector<tuple<int,int,ll,int>> qr;
unordered_map<ll,int> mp[N];
ll pw[N]; int ans[N];
i128 mul(ll a,ll b){return (i128)a * b % mod;}
int main(){
    freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m; int mx = 0;
    for(int i = 1;i <= n;i ++){
        cin >> s >> t,p[i] = i;
        ll h = 0; mx = max(mx,(int)t.size());
        for(char c : s) h = (mul(h,B) + c - 'a' + 1) % mod,h1[i].push_back(h);
        h = 0;
        for(char c : t) h = (mul(h,B) + c - 'a' + 1) % mod,h2[i].push_back(h);
        int x = t.size() - 1;
        while(x >= 0 && s[x] == t[x]) x --;
        len[i] = t.size(),con[i] = max(1,x + 1);
    }pw[0] = 1;
    sort(p+1,p+n+1,[&](int x,int y){return len[x] < len[y];});
    for(int i = 1;i <= mx;i ++) pw[i] = mul(pw[i-1],B);
    for(int i = 1;i <= m;i ++){
        cin >> s >> t;
        if(s.size() != t.size()) continue;
        int l = -1,r = -1,fg = 0;
        for(int i = 0;i < s.size();i ++){
            if(s[i] != t[i]){
                if(l == -1) l = i;
                r = i;
            }
        }assert(l != -1);
        ll h1 = 0,h2 = 0;
        for(int j = l;j <= r;j ++) 
            h1 = (mul(h1,B) + s[j] - 'a' + 1) % mod,
            h2 = (mul(h2,B) + t[j] - 'a' + 1) % mod;
        for(int j = l;j >= 0;j --){
            if(r - j + 1 > mx) break;
            qr.emplace_back(t.size() - j,r - j + 1,(mul(h1,pw[r - j + 1]) + h2) % mod,i);
            //cerr << "qry " << r - j << " " << i << " " << h1 << " " << h2 << "\n";
            if(!j) break;
            h1 = (h1 + mul(s[j - 1] - 'a' + 1,pw[r - j + 1])) % mod;
            h2 = (h2 + mul(t[j - 1] - 'a' + 1,pw[r - j + 1])) % mod;
        }
    }
    int j = 1;
    sort(qr.begin(),qr.end());
    for(auto [l,ln,h,id] : qr){
        // cerr << l << " " << ln << " " << id << "\n";
        while(j <= n && len[p[j]] <= l){
            int x = p[j];
            for(int i = con[x];i <= len[x];i ++)
                mp[i][((mul(h1[x][i-1],pw[i]) + h2[x][i-1])) % mod] ++;
            j ++;
        }if(mp[ln].count(h)) ans[id] += mp[ln][h];
    }
    // for(int i = mx;i >= 1;i --){
    //     for(int k = j + 1;k <= n;k ++){
    //         ll old = (mul(h1[p[k]][i],pw[i+1]) + h2[p[k]][i]) % mod;
    //         ll nw = (mul(h1[p[k]][i-1],pw[i]) + h2[p[k]][i-1]) % mod;
    //         //cerr << "add " << i << " " << h1[p[k]][i-1] << " " << h2[p[k]][i-1] << "\n";
    //         assert(mp[old]);
    //         mp[old] --,mp[nw] ++;
    //     }while(j && len[p[j]] == i){
    //         ll nw = (mul(h1[p[j]][i-1],pw[i]) + h2[p[j]][i-1]) % mod;
    //         //cerr << "add2 " << i << " " << h1[p[j]][i-1] << " " << h2[p[j]][i-1] << "\n";
    //         mp[nw] ++,j --;
    //     }for(auto [h,id] : qr[i]) if(mp.count(h)) ans[id] += mp[h];
    // }
    for(int i = 1;i <= m;i ++) cout << ans[i] << "\n";
}
