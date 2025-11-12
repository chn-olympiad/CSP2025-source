#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
string s[N][2];
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> s[i][0] >> s[i][1];
        s[i][0] = " " + s[i][0];
        s[i][1] = " " + s[i][1];
        // int len = s[i][0].size();
        // int l = 0, r = len - 1;
        // while(l < len && s[i][0][l] == s[i][1][l]) l++;
        // while(r <)
    }
    while(q--) {
        string ss, st;
        cin >> ss >> st;
        if(ss.size() != st.size()) {
        	cout << "0\n";
        	continue;
		}
        ss = " " + ss;
        st = " " + st;
        int l = 1, r = ss.size()-1;
        int m = ss.size()-1;
        //cout << ss << " " << r << endl;
        while(l <= m && ss[l] == st[l])l++;
        l--;
        while(r > 0 && ss[r] == st[r])r--;
        r++;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int len = s[i][0].size()-1;
            //cout << len<<endl;
            for (int j = 1; j <= ss.size()-1 - len; j++) {
                if(ss.substr(j, len) != s[i][0].substr(1, len)) continue;
                //cout << j << endl;
                if(st.substr(j, len) != s[i][1].substr(1, len)) continue;
                //cout << j << endl;
                if(j + len >= r && j <= l + 1) {
                    ans++;
                    break;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
/*

g++ -std=c++14 -O2 -Wall -Wextra -Wl,--stack=512000000 1.cpp -o 1
*/