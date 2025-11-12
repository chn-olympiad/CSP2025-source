#include<bits/stdc++.h>
using namespace std;
struct people{
    int w[3],maxi,delta;
    bool operator < (const people other)const{return delta > other.delta;}
}P[100010];
int N,ans;
priority_queue<people>Q[3];
void solve(){
    cin >> N;
    for(int i = 1;i <= N;++i){
        cin >> P[i].w[0] >> P[i].w[1] >> P[i].w[2];
        int maxn = 0,sec = 0;
        for(int j = 0;j < 3;++j){
            if(P[i].w[j] >= maxn){
                sec = maxn;
                maxn = P[i].w[j];
                P[i].maxi = j;
            }else if(P[i].w[j] >= sec){
                sec = P[i].w[j];
            }
            P[i].delta = maxn-sec;
        }
        Q[P[i].maxi].push(P[i]);
        ans += P[i].w[P[i].maxi];
        if(Q[P[i].maxi].size() > (N>>1)){
            ans -= Q[P[i].maxi].top().delta;
            Q[P[i].maxi].pop();
        }
    }
    cout << ans << "\n";
}
void clear(){
    ans = 0;
    while(!Q[0].empty()){Q[0].pop();}
    while(!Q[1].empty()){Q[1].pop();}
    while(!Q[2].empty()){Q[2].pop();}
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T = 1;cin >> T;
    for(int i = 1;i <= T;++i){clear();solve();}
    return 0;
}
/* 
g++ -o club club.cpp -std=c++14 -fsanitize=undefined,address -g
g++ -o club club.cpp -std=c++14 -fsanitize=undefined,address -O2 
g++ -o club club.cpp -std=c++14 -g
g++ -o club club.cpp -std=c++14 -O2
*/