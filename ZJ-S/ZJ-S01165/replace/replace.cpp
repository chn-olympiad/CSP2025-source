#include<bits/stdc++.h>
// #define int long long
using namespace std;
int read(){
    int s = 0, f = 1;
    signed c = getchar();
    for(; !isdigit(c); c = getchar()) if(c == '-') f = -f;
    for(; isdigit(c); c = getchar()) s = (s * 10) + (c ^ 48);
    return s * f;
}
void write(int x){
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) write(x / 10);
    putchar('0' + x % 10);
    return;
}
const int N = 5e6 + 10;
const unsigned long long bas = 43;
int n, Q, len[N];
char s1[N], s2[N];
unsigned long long ha[N], hb[N], pw[N];
queue<int> q;
vector<pair<int, int> > t1, t2;
set<pair<int, int> > St;
struct TRIE{
    int cnt, tr[N][26], fail[N];
    vector<int> val[N];
    void ins(char *s, int v){
        int len = strlen(s), p = 0;
        for(int i = 0, t; i < len; ++ i){
            t = s[i] - 'a';
            if(!tr[p][t]) tr[p][t] = ++ cnt;
            p = tr[p][t];
        }
        val[p].push_back(v);
        return;
    }
    void build(){
        for(int i = 0; i < 26; ++ i)
            if(tr[0][i]) q.push(tr[0][i]);
        for(int u; q.size();){
            u = q.front();
            q.pop();
            for(int v : val[fail[u]])
                val[u].push_back(v);
            for(int i = 0; i < 26; ++ i){
                if(tr[u][i]) fail[tr[u][i]] = tr[fail[u]][i], q.push(tr[u][i]);
                else tr[u][i] = tr[fail[u]][i];
            }
        }
        return;
    }
    vector<pair<int, int> > query(char *s){
        vector<pair<int, int> > res;
        int len = strlen(s), p = 0;
        for(int i = 0, t; i < len; ++ i){
            t = s[i] - 'a';
            p = tr[p][t];
            if(val[p].size()){
                for(int v : val[p]){
                    res.emplace_back(i, v);
                }
            }
        }
        return res;
    }
}A, B;
unsigned long long gethash(unsigned long long *hh, int l, int r){
    if(l > r) return 0;
    return (hh[r] - hh[l - 1] * pw[r - l + 1]);
}
bool check(int L, int v, int k){
    // cout << 1 << " " << k - len[v] + 1 << "\n";
    // cout << k + 2 << " " << L << "\n";
    for(int i = 1; i <= k - len[v] + 1; ++ i)
        if(s1[i - 1] != s2[i - 1]) return 0;
    for(int i = k + 2; k <= L; ++ i)
        if(s1[i - 1] != s2[i - 1]) return 0;
    return 1;
    // return gethash(ha, 1, k - len[v] + 1) == gethash(hb, 1, k - len[v] + 1)
    //     && gethash(ha, k + 2, L) == gethash(hb, k + 2, L);
}
signed main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    n = read(), Q = read();
    for(int i = 1; i <= n; ++ i){
        scanf("%s %s", s1, s2);
        len[i] = strlen(s1);
        A.ins(s1, i);
        B.ins(s2, i);
    }
    A.build(), B.build();
    pw[0] = 1;
    for(int i = 1; i <= 5000000; ++ i)
        pw[i] = (unsigned long long)pw[i - 1] * bas;
    for(int res, len; Q --;){
        scanf("%s", s1);
        scanf("%s", s2);
        len = strlen(s1);
        ha[0] = hb[0] = 0;
        for(int i = 1; i <= len; ++ i){
            ha[i] = ha[i - 1] + (unsigned long long)s1[i - 1] * bas;
            hb[i] = hb[i - 1] + (unsigned long long)s2[i - 1] * bas;
        }
        // cout << gethash(ha, 1, 2) << " " << gethash(hb, 1, 2) << "\n";
        // cout << gethash(ha, 5, 5) << " " << gethash(hb, 5, 5) << "\n";
        t1.clear(), t2.clear();
        t1 = A.query(s1), t2 = B.query(s2);
        St.clear();
        for(pair<int, int> Pair : t1)
            St.insert(Pair);
        res = 0;
        for(pair<int, int> Pair : t2){
            if(St.find(Pair) != St.end() && check(len, Pair.second, Pair.first)){
                // cout << Pair.first << " " << Pair.second << "\n";
                ++ res;
            }
        }
        write(res);
        puts("");
    }
    return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

4 1
xabcx xadex
ab cd
bc de
aa bb
aaaa bbbb

4 1
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
*/