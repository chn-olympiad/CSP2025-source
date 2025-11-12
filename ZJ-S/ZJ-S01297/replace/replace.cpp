#include <iostream>
#include <string>
using namespace std;

int N,Q;
string T[2];
string S[200008][2];

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> N>>Q;
    for (int i = 1; i <= N;i++) {
        cin >> S[i][0]>>S[i][1];
    }
    while(Q--) {
        cin >> T[0] >> T[1];
        int ans = 0;
        for (int i = 1; i <= N;i++) {
            int ls = S[i][0].size();
            int lt = T[0].size();
            if (ls>lt)
                continue;
            int p=0;
            bool is = false;
            int j = 0;
            for (j = 0; j <= lt;j++) {
                if (T[0][j]==S[i][0][p] && T[1][j]==S[i][1][p]) {
                    p++;
                }else{
                    if (T[0][j]!=T[1][j]) {
                        is = false;
                        break;
                    }
                    if (p) {
                        is = false;
                        break;
                    }
                }
                if (p==ls) {
                    is = true;
                    break;
                }
            }
            if (is)
            for (j++; j <= lt;j++) {
                if (T[0][j]!=T[1][j]) {
                    is = false;
                    break;
                }
            }
            if (is) {
                ans++;
            }
        }
        cout << ans<<endl;
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
xabcx xadex
*/