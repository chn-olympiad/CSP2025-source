#include<bits/stdc++.h>
using namespace std;
char T[110][2][210],S[3][210];
int N,Q,len[110],L,ans;
void solve(){
    cin >> N >> Q;
    for(int i = 1;i <= N;++i){
        cin >> T[i][0];
        cin >> T[i][1];
        len[i] = strlen(T[i][0]);
    }
    for(int r = 1;r <= Q;++r){
        cin >> S[0];
        cin >> S[1];
        L = strlen(S[0]);ans = 0;
        for(int i = 0;i < L;++i){
            for(int j = 1;j <= N;++j){
                if(i+len[j] > L){continue;}
                bool flag = 1;
                for(int t = 0;t < len[j];++t){
                    if(S[0][i+t] != T[j][0][t]||S[1][i+t] != T[j][1][t]){
                        flag = 0;
                        break;
                    }
                }
                for(int t = i+len[j];t < L;++t){if(S[0][t] != S[1][t]){flag = 0;break;}}
                if(flag){++ans;}
            }
            if(S[0][i] != S[1][i]){break;}
        }
        cout << ans << "\n";
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int T = 1;
    for(int i = 1;i <= T;++i){solve();}
    return 0;
}
/* 
g++ -o replace replace.cpp -std=c++14 -g
g++ -o replace replace.cpp -std=c++14 -O2
*/