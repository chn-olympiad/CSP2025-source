#include<bits/stdc++.h>
#define ull unsigned long long
#define B 1451
#define C 1451117
using namespace std;

int n, m;

map<ull, vector<pair<ull, ull>>> rec;

ull get(string s) {
    ull rsl=0;
    for(int i=0; i<s.size(); ++i)
        rsl=rsl*B+s[i]-'a'+1;
    return rsl;
}

unordered_map<ull, bool> vis[2];

signed main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    string s, t;
    for(int i=1; i<=n; ++i) {
        cin >> s >> t;
        int len=s.size();
        s=' '+s, t=' '+t;
        int l=0, r=len+1;
        while(l<len && s[l+1]==t[l+1]) ++l;
        while(r>1 && s[r-1]==t[r-1]) --r;
        if(l>r) continue;
        ull lft=0, rgh=0, mid=0;
        if(l>=1) lft=get(s.substr(1, l));
        mid=get(s.substr(l+1, r-l-1))*C+
            get(t.substr(l+1, r-l-1));
        if(r<=len) rgh=get(s.substr(r, len-r+1));
        rec[mid].push_back({lft, rgh});
    }
    while(m--) {
        cin >> s >> t;
        int rsl=0, len=s.size();
        s=' '+s, t=' '+t;
        int l=0, r=len+1;
        while(l<len && s[l+1]==t[l+1]) ++l;
        while(r>1 && s[r-1]==t[r-1]) --r;
        ull mid=get(s.substr(l+1, r-l-1))*C+
            get(t.substr(l+1, r-l-1));

        vis[0].clear(), vis[1].clear();
        vis[0][0]=vis[1][0]=1;
        ull v=0;
        for(int i=r; i<=len; ++i) {
            v=v*B+s[i]-'a'+1;
            vis[1][v]=1;
        }
        v=0;
        ull w=1;
        for(int i=l; i>=1; --i) {
            v=v+(s[i]-'a'+1)*w;
            vis[0][v]=1;
            w=w*B;
        }

        for(int i=0; i<rec[mid].size(); ++i) {
            ull lft=rec[mid][i].first;
            ull rgh=rec[mid][i].second;
            if(vis[0][lft] && vis[1][rgh])
                ++rsl;
        }
        cout << rsl << '\n';
    }
    return 0;
}