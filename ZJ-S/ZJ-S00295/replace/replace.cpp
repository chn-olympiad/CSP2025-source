#include<bits/stdc++.h>
using namespace std;
int n, q;
struct node{
    string s1, s2, pre, suf;
    int id;
}a[400050], b[400050];
pair<int, int> c[400050], d[400050];
int ans[200050];
bool cmp(node x, node y){
    return x.s1 == y.s1 ? (x.s2 == y.s2 ? x.id < y.id : x.s2 < y.s2) : x.s1 < y.s1;
}
int tot;
string s1, s2;
void add(int id){
    node nw;
    nw.id = id;
    cin >> s1 >> s2;
    if(s1.size() != s2.size() || s1 == s2){
        return;
    }
    int l, r;
    for(int i = 0; i < (int)(s1.size()); i++){
        if(s1[i] != s2[i]){
            l = i;
            break;
        }
    }
    for(int i = (int)(s1.size()) - 1; i >= 0; i--){
        if(s1[i] != s2[i]){
            r = i;
            break;
        }
    }
    nw.s1 = s1.substr(l, r-l+1), nw.s2 = s2.substr(l, r-l+1);
    nw.pre = s1.substr(0, l), nw.suf = s1.substr(r+1);
    reverse(nw.pre.begin(), nw.pre.end());
    a[++tot] = nw;
}
void Sort(node *a, int len){
    if(len == 1)return;
    int mid = 1+len>>1;
    int l = 1, r = mid+1;
    Sort(a, mid);
    Sort(a+mid, len-mid);
    int cnt = 0;
    while(l <= mid && r <= len){
        if(cmp(a[l], a[r])){
            b[++cnt] = a[l++];
        }else{
            b[++cnt] = a[r++];
        }
    }
    while(l <= mid)b[++cnt] = a[l++];
    while(r <= len)b[++cnt] = a[r++];
    for(int i = 1; i <= cnt; i++)a[i] = b[i];
    return;
}
struct tree{
    int tr[5000050][26];
    int tot;
    int dfn[5000050], rnk[5000050], sz[5000050], cnt;
    int insert(string s){
        int now = 0;
        for(auto ch : s){
            int op = ch - 'a';
            if(!tr[now][op])tr[now][op] = ++tot;
            now = tr[now][op];
        }
        return now;
    }
    void dfs(int now){
        sz[now] = 1;
        dfn[now] = ++cnt, rnk[cnt] = now;
        for(int i = 0; i < 26; i++){
            if(tr[now][i]){
                dfs(tr[now][i]);
                sz[now] += sz[tr[now][i]];
            }
        }
    }
    void init(){
        dfs(0);
    }
    pair<int, int> get(string s){
        int now = 0;
        for(auto ch : s){
            int op = ch - 'a';
            if(!tr[now][op])return {-1, -1};
            now = tr[now][op];
        }
        return {dfn[now], dfn[now] + sz[now] - 1};
    }
    void clr(){
        for(int i = 0; i <= tot; i++){
            for(int j = 0; j < 26; j++)tr[i][j] = 0;
        }
        cnt = tot = 0;
    }
}T;
vector<pair<int, int>> Add[1000050], Del[1000050], Qry[1000050];
int f[5000050];
int N;
int lowbit(int x){
    return x & -x;
}
void chg(int now, int x){
    while(now <= N){
        f[now] += x;
        now += lowbit(now);
    }
}
int qry(int now){
    int res = 0;
    while(now){
        res += f[now];
        now -= lowbit(now);
    }
    return res;
}
void solve(node *a, int len){
    for(int i = 1; i <= len; i++){
        if(!!a[i].id){
            vector<int> vec;
            for(int j = i; j <= len; j++){
                d[j].first = T.insert(a[j].pre);
            }
            T.init();
            for(int j = 1; j < i; j++){
                c[j] = T.get(a[j].pre);
                if(c[j].first == -1)continue;
                vec.emplace_back(c[j].first);
                vec.emplace_back(c[j].second + 1);
            }
            for(int j = i; j <= len; j++)d[j].first = T.dfn[d[j].first], vec.emplace_back(d[j].first), vec.emplace_back(d[j].first+1);
            sort(vec.begin(), vec.end());
            vec.erase(unique(vec.begin(), vec.end()), vec.end());
            for(int j = 1; j <= len; j++){
                if(j < i){
                    if(c[j].first != -1){
                        c[j].first = lower_bound(vec.begin(), vec.end(), c[j].first) - vec.begin() + 1;
                        c[j].second = lower_bound(vec.begin(), vec.end(), c[j].second+1) - vec.begin();
                    }
                }else{
                    d[j].first = lower_bound(vec.begin(), vec.end(), d[j].first) - vec.begin() + 1;
                }
            }
            T.clr();
            for(int j = i; j <= len; j++){
                d[j].second = T.insert(a[j].suf);
            }
            T.init();
            for(int j = 1; j < i; j++){
                auto res = T.get(a[j].suf);
                if(res.first == -1 || c[j].first == -1)continue;
                Add[c[j].first].emplace_back(res);
                Del[c[j].second+1].emplace_back(res);
            }
            for(int j = i; j <= len; j++){
                Qry[d[j].first].emplace_back(T.dfn[d[j].second], a[j].id);
            }
            N = T.cnt+1;
            for(int j = 1; j <= (int)vec.size(); j++){
                for(auto [l, r] : Add[j])chg(l, 1), chg(r+1, -1);
                for(auto [l, r] : Del[j])chg(l, -1), chg(r+1, 1);
                for(auto [p, id] : Qry[j])ans[id] = qry(p);
                Add[j].clear(), Del[j].clear(), Qry[j].clear();
            }
            T.clr();
            return;
        }
    } 
}
signed main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++)add(0);
    for(int i = 1; i <= q; i++)add(i);
    Sort(a, tot);
    int pre = 0;
    for(int i = 1; i <= tot; i++){
        if(i > 1 && (a[i].s1 != a[i-1].s1 || a[i].s2 != a[i-1].s2)){
            solve(a+pre, i-pre-1);
            pre = i-1;
        }
    }
    solve(a+pre, tot-pre);
    for(int i = 1; i <= q; i++){
        cout << ans[i] << '\n';
    }
    return 0;
}