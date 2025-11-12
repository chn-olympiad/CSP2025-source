#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N = 200100, M = 5000100,base=137,mod=998244353;
int n, m, tot;
string ta,tb,s[N],t[N];
int hs[N], ht[N];
// struct node{
//     int cnt, p, nxt[26];
// } a[M];
// void build(){
//     a[tot=1].p = 0;
//     for (int i = 1; i <= m;i++){
//         int cur = 1;
//         a[cur].cnt++;
//         for (int j = 0; j < t[i].length();j++){
//             if(!a[cur].nxt[t[i][j]-'a'])
//                 a[cur].nxt[t[i][j] - 'a'] = ++tot;
//             cur = a[cur].nxt[t[i][j] - 'a'];
//             a[cur].cnt++;
//         }
//     }
//     queue<int> q;
//     q.push(1);
//     while(!q.empty()){
//         int now = q.front();
//         q.pop();
//         for (int i = 0; i < 26;i++){
//             if(a[now].nxt[i]){
//                 q.push(a[now].nxt[i]);
//                 int cur = now;
//                 while(cur){
//                     cur = a[cur].p;
//                     if(a[cur].nxt[i]){
//                         a[a[now].nxt[i]].p = a[cur].nxt[i];
//                         break;
//                     }
//                 }
//             }
//         }
//     }
// }
// int query(string st){
//     cout << st << '\n';
//     int cur = 1, ret = 0;
//     for (int i = 0; i < st.length();i++){
//         while(!a[cur].nxt[st[i]-'a']&&cur)
//             cur = a[cur].p;
//         if(a[cur].nxt[st[i] - 'a']) cur = a[cur].nxt[st[i] - 'a'];
//         cout << cur << ' ';
//     }
//     while(cur){
//         ret += a[cur].cnt;
//         cur = a[cur].p;
//     }
//     cout << '\n';
//     return ret;
// }
map<int, int> cnt;
signed main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        cin >> ta >> tb;
        int len = ta.length();
        for (int j = 0; j < len;j++){
            s[i] += ta[j], s[i] += tb[j];
            hs[i] = (hs[i] * base + ta[j]) % mod;
            hs[i] = (hs[i] * base + tb[j]) % mod;
        }
        // cout << i << ' ' << hs[i] << '\n';
        cnt[hs[i]]++;
    }
    for (int i = 1; i <= m;i++){
        cin >> ta >> tb;
        if(ta.length()!=tb.length()){
            cout << "0\n";
            continue;
        }
        int len = ta.length();
        int ans = 0;
        int l = -1, r = len-1, w = 0;
        for (int j = 0; j < len;j++){
            t[i] += ta[j], t[i] += tb[j];
            if(ta[j]!=tb[j]&&l==-1)
                l = j;
            if(l!=-1&&ta[j]==tb[j]){
                r = j-1;
            }
        }
        // cout << l << ' ' << r << '\n';
        for (int j = 0; j <= l;j++){
            int w = 0;
            for (int k = j; k < len;k++){
                w = (w * base + t[i][2 * k]) % mod;
                w = (w * base + t[i][2 * k + 1]) % mod;
                if(k>=r)
                    // cout<<j<<' '<<k<<' '<<w<<'\n',
                    ans += cnt[w];
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}