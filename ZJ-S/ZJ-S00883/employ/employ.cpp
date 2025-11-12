#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int N = 510;
char s[N];
int n,m;
int c[N];
void work1(){
    int flag = 1;
    for(int i = 1;i <= n;i++)
        if(c[i] == 0 || s[i] == '0') flag = 0;
    if(flag == 0) printf("0\n");
    else{
        long long now = 1;
        for(int i = 1;i <= n;i++) now = now * i % MOD;
        printf("%lld\n",now);
    }
}
long long dp[20][1<<18];
long long dfs(int now,int num){
    if(dp[num][now] != -1) return dp[num][now];
    int id = 1;
    for(int i = 0;i < n;i++)
        if((now >> i) & 1) id += 1;
    if(id == n+1)
        return num >= m;
    dp[num][now] = 0;
    for(int i = 0;i < n;i++){
        if(((now >> i) & 1)==0){
            int tmp = now | (1 << i);
            if(c[i+1] > id - num - 1 && s[id] == '1') dp[num][now] = (dp[num][now]+dfs(tmp,num+1)) % MOD;
            else dp[num][now] = (dp[num][now]+dfs(tmp,num)) % MOD;
        }
    }
    return dp[num][now];
}
void work(){
    memset(dp,-1,sizeof(dp));
    printf("%lld\n",dfs(0,0));
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    for(int i = 1;i <= n;i++) scanf("%d",&c[i]);
    if(n == m) work1();
    else work();
    return 0;
}