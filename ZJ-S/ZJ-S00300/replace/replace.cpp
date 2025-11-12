// KMP
# include <bits/stdc++.h>
using namespace std;
# define int long long
# define fi first
# define se second
# define pss pair<string,string>
# define rep(i,a,b) for (int i = a; i <= b; i++)

const int N = 2e5 + 5;
pss s[N];
pss t[N];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    int n, q; cin >> n >> q;
    rep(i,1,n) cin >> s[i].first >>s[i].second;
    rep(i,1,q){
        int cnt = 0;
        string s1, s2;
        cin >> s1 >> s2;
        rep(j,1,n){
            string t1 = s[j].first;
            string t2 = s[j].second;
            int pos1 = s1.find(t1);
            int pos2 = s2.find(t2);
            if (pos1 != -1 && pos2 != -1){
                if (pos1 == pos2){
                    int flag = 1;
                    rep(k,0,pos1 - 1){
                        if (s1[k] != s2[k]){
                            flag = 0;
                        }
                    }
                    rep(k,pos1 + t1.length(),s1.length()-1){
                        if (s1[k] != s2[k]){
                            flag = 0;
                        }
                    }
                    cnt += flag;
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}
