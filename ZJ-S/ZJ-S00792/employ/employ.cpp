#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int N,M,A[510],ans,cnt[2];
char S[510];
bool vis[15];
void dfs(int now,int have){
    if(now > N){
        if(have >= M){++ans;}
        return;
    }
    for(int i = 1;i <= N;++i){
        if(vis[i]){continue;}
        vis[i] = 1;
        if(S[now] == '1'&&now-have <= A[i]){dfs(now+1,have+1);}
        else{dfs(now+1,have);}
        vis[i] = 0;
    }
}
void solve(){
    cin >> N >> M;
    cin >> (S+1);
    for(int i = 1;i <= N;++i){cin >> A[i];}
    for(int i = 1;i <= N;++i){cnt[S[i]-'0']++;}
    if(cnt[1] < M){cout << "0\n";return;}
    if(cnt[1] <= 10){dfs(1,0);cout << ans << "\n";return;}
    // dp[0][0][0] = 1;
    // for(int i = 0;i < cnt[1];++i){
    //     for(int j = 0;j < cnt[1];++j){
    //         for(int k = 0;k < N;++k){
    //             for(int l = k+1;l <= N;++l){
    //                 if(l-k <= A[l]){dp[i+1][j+1][l] += dp[i][j][l];}
    //                 else{dp[i+1][j][k] += dp[i][j][l];}
    //             }
    //         }
    //     }
    // }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int T = 1;
    for(int i = 1;i <= T;++i){solve();}
    return 0;
}
/* 
g++ -o employ employ.cpp -std=c++14 -g
g++ -o employ employ.cpp -std=c++14 -O2
*/