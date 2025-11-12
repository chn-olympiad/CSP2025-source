#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N = 2e5 + 15;
const int M = 5e6 + 15;
const ull base = 137;
int n,q,c[N];
namespace subtask1{
ull ha[N],hb[N];
ull h1[M],h2[M];
ull B[M];
    void work(){
        B[0] = 1;
        for(int i = 1;i < M;i ++)
            B[i] = B[i - 1] * base;
        for(int i = 1;i <= n;i ++){
            string a,b;cin >> a >> b;
            int m = a.size();c[i] = m;
            for(int j = 0;j < a.size();j ++)
                ha[i] = ha[i] * base + a[j];
            for(int j = 0;j < b.size();j ++)
                hb[i] = hb[i] * base + b[j];
        }
        while(q --){
            string s,t;cin >> s >> t;
            if(s.size() != t.size()){
            	cout << 0 << '\n';
            	continue;
			} 
            int m = s.size();
            for(int i = 0;i < m;i ++){
                h1[i + 1] = h1[i] * base + s[i];
                h2[i + 1] = h2[i] * base + t[i];
            }
            int cnt = 0;
            for(int i = 1;i <= n;i ++){
                for(int l = 1;l + c[i] - 1 <= m;l ++){
                    int r = l + c[i] - 1;
                    if(h1[r] - h1[l - 1] * B[r - l + 1] == ha[i] &&
                    h2[r] - h2[l - 1] * B[r - l + 1] == hb[i] &&
                    h1[l - 1] == h2[l - 1] &&
                    h1[m] - h1[r] * B[m - r] == h2[m] - h2[r] * B[m - r]){
                        cnt ++;
                    }
                }
            }cout << cnt << '\n';
        }
    }
}
namespace subtask2{
int c[N],pre[N],suf[N];
    void work(){
        for(int i = 1;i <= n;i ++){
            string a,b;cin >> a >> b;
            int pla,plb;
            for(int j = 0;j < a.size();j ++){
                if(a[j] == 'b') pla = j;
                if(b[j] == 'b') plb = j;
            }
            pre[i] = pla;suf[i] = a.size() - pla;
            c[i] = pla - plb;
        }
        while(q --){
            string s,t;cin >> s >> t;
            int pls,plt;
            for(int i = 0;i < s.size();i ++){
                if(s[i] == 'b') pls = i;
                if(t[i] == 'b') plt = i;
            }
            int cnt = 0;
            for(int i = 1;i <= n;i ++){
                if(pre[i] <= pls && suf[i] <= s.size() - pls && c[i] == pls - plt)
                    cnt ++;
            }cout << cnt << '\n';
        }
    }
}
void solve(){
    cin >> n >> q;
    if(n <= 1000 && q > 1) return subtask1::work();
    return subtask2::work();
}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while(T --) solve();
    return 0;
}
/*
no idea
ACAM?
*/