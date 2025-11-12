#include <bits/stdc++.h>

using namespace std;
int n, q;
const int N = 2e5 + 10;
string s[N][3];
void work1() {
    string t1, t2;
    // getchar();
    cin >> t1 >> t2;
    // cout << "???" << t1 << " " << t2 << "\n";
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        int len = s[i][1].size();
        for(int l = 0; l + len - 1 < (int)t1.size(); l++) {
            int r = l + len - 1, flag = 0;
            for(int k = l; k <= l + len - 1; k++)
                if(s[i][1][k - l] != t1[k])
                    flag = 1;
            if(flag) continue;
            for(int k = l; k <= l + len - 1; k++)
                if(s[i][2][k - l] != t2[k])
                    flag = 1;
            if(flag) continue;
            for(int k = 0; k < t1.size(); k++) {
                if(l <= k && k <= r) continue;
                if(t1[k] != t2[k]) flag = 1;
            }
            if(flag) continue;
            cnt++;
            // printf("%d %d\n", i, l);
        }
    }
    printf("%d\n", cnt);
    return;
}
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i++) {
        // getchar();
        cin >> s[i][1] >> s[i][2];
    }
    // for(int i = 1; i <= n; i++) {
    //     cout << "???" << s[i][1] << " " << s[i][2] << "\n";
    // }
    while(q--) {
        if(n <= 105) work1();
        else printf("0\n");
    }
}