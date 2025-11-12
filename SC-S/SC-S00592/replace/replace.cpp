#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
const int N = 5e6 + 3;
const ull B = 233;
int n, q;
ull hshval[N];

namespace BIT{
    int s[N];
    void init(){
        memset(s, 0, sizeof s);
    }
    int lowbit(int x){
        return x & (-x);
    }
    void modify(int x, int val){
        for(; x < N; x += lowbit(x))s[x] += val;
    }
    int qry(int x){
        int res = 0;
        for(; x; x -= lowbit(x))res += s[x];
        return res;
    }
}

namespace acam{
    int ch[N][26], fail[N];
    int endpos[N];
    vector<int> t[N];
    int dfn[N], siz[N], pdfn, tot;
    void build(string s, int id){
        int cur = 0, len = s.size();
        for(int i = 0; i < len; i++){
            if(!ch[cur][s[i] - 'a'])ch[cur][s[i] - 'a'] = ++tot;
            cur = ch[cur][s[i] - 'a'];
        }
        endpos[id] = cur;
    }
    queue<int> q;
    void buildac(){
        for(int i = 0; i < 26; i++)
            if(ch[0][i])fail[ch[0][i]] = 0, q.push(ch[0][i]);
        while(!q.empty()){
            int u = q.front();q.pop();
            for(int i = 0; i < 26; i++){
                if(ch[u][i])fail[ch[u][i]] = ch[fail[u]][i], q.push(ch[u][i]);
                else ch[u][i] = ch[fail[u]][i];
            }
        }
        for(int i = 1; i <= tot; i++)
            t[fail[i]].emplace_back(i);
    }
    void dfs(int u){
        dfn[u] = ++pdfn, siz[u] = 1;
        for(int v: t[u])
            dfs(v), siz[u] += siz[v];
    }
    // void dbg(){
        // for(int i = 0; i <= tot; i++){
            // cerr<<i<<": "<<endl;
            // for(int j = 0; j < 26; j++)
                // if(ch[i][j])cerr<<"["<<char(j + 'a')<<" "<<ch[i][j]<<"] ";
            // cerr<<endl;
            // cerr<<fail[i]<<endl;
        // }
        // for(int i = 0; i <= tot; i++){
            // cerr<<i<<": "<<endl;
            // cerr<<dfn[i]<<' '<<siz[i]<<endl;
        // }
    // }
}

string s1, s2;

int ans[N];
struct Op{
    ull hsh;
    int pos, id;
};
vector<Op> seq;

main(){
    freopen("replace.in", "r", stdin), freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> s1 >> s2;
        int len = s1.size();
        ull hsh = 0;
        for(int j = 0; j < len; j++)
            hsh = hsh * B + (s2[j] - s1[j]);
        hshval[i] = hsh;
        acam::build(s1, i);
        seq.push_back({hsh, acam::endpos[i], 0});
        // cerr<<i<<": "<<acam::endpos[i]<<' '<<hsh<<endl;
    }
    acam::buildac(), acam::dfs(0);
    // acam::dbg();
    // exit(0);
    for(int i = 1; i <= q; i++){
        cin >> s1 >> s2;
        int len = s1.size();
        if(len != s2.size())continue;
        ull hsh = 0;
        int pos = len - 1;
        while(s2[pos] == s1[pos])pos--;
        int cur = 0;
        for(int j = 0; j < len; j++){
            hsh = hsh * B + (s2[j] - s1[j]);
            cur = acam::ch[cur][s1[j] - 'a'];
            if(j >= pos)seq.push_back({hsh, cur, i});
            // cerr<<j<<": "<<cur<<' '<<hsh<<endl;
        }
        // cerr<<endl;
    }
    // exit(0);
    sort(seq.begin(), seq.end(), [&](const auto &x, const auto &y){
        return (x.hsh != y.hsh) ? (x.hsh < y.hsh) : (x.id < y.id);
    });
    int siz = seq.size();
    for(int l = 0; l < siz; ){
        int r = l;
        while(r < siz && seq[r].hsh == seq[l].hsh)r++;
        for(int i = l; i < r; i++){
            if(seq[i].id == 0)BIT::modify(acam::dfn[seq[i].pos], 1), BIT::modify(acam::dfn[seq[i].pos] + acam::siz[seq[i].pos], -1);
            else ans[seq[i].id] += BIT::qry(acam::dfn[seq[i].pos]);
        }
        for(int i = l; i < r; i++){
            if(seq[i].id == 0)BIT::modify(acam::dfn[seq[i].pos], -1), BIT::modify(acam::dfn[seq[i].pos] + acam::siz[seq[i].pos], 1);
            else break;
        }
        l = r;
    }
    for(int i = 1; i <= q; i++)printf("%d\n", ans[i]);
}