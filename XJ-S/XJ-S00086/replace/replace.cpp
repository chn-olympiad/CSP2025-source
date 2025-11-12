#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 5;

int n, q;
string s1[N], s2[N];
int S[N], T[N], L[N]; 

void solve(){
    cin >> n >> q;
    for (int i = 1; i <= n; i ++){
        cin >> s1[i] >> s2[i];
        int len1 = s1[i].length(), len2 = s2[i].length();
        for (int j = 0; j < len1; j ++){
            if (s1[i][j] == 'b'){
                S[i] = j, T[i] = len1 - j - 1;
                break;
            }
        }
        for (int j = 0; j < len2; j ++){
            if (s2[i][j] == 'b'){
                L[i] = j - S[i];
                break;
            }
        }
    }
    for (int i = 1; i <= q; i ++){
        string t1, t2;
        cin >> t1 >> t2;
        if (t1.length() != t2.length()){
            cout << "0\n";
            continue;
        }
        int ss, tt, l, len1 = t1.length(), len2 = t2.length(), ans = 0;
        for (int j = 0; j < len1; j ++){
            if (t1[j] == 'b'){
                ss = j, tt = len1 - j - 1;
                break;
            }
        }
        for (int j = 0; j < len2; j ++){
            if (t2[j] == 'b'){
                l = j - ss;
                break;
            }
        }
        // cout << ss << " " << tt << " " << l << "\n";
        for (int j = 1; j <= n; j ++){
            if (L[j] != l) continue;
            if (ss >= S[j] && tt >= T[j]) ++ ans;
        }
        cout << ans << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    clock_t st = clock();
        solve();
    clock_t ed = clock();
    // printf("\nThe time is %.3lf s", (double)(ed - st) / CLOCKS_PER_SEC);
}