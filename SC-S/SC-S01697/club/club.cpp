#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=1e5+15;
struct node{
    int a,b,c;
}A[N];
int n;
void solve(){
    cin>>n;
    int suma=0,sumb=0,sumc=0;
    for(int i=1;i<=n;i++)
        cin>>A[i].a>>A[i].b>>A[i].c,suma+=A[i].a,sumb+=A[i].b,sumc+=A[i].c;
    if(sumb==0&&sumc==0){
        cout<<suma<<endl;
        return;
    }
    if(sumc==0){
        bool now=0;
        vector<vector<int>>dp(2,vector<int>(n/2+1,0));
        for(int i=1;i<=n;i++){
            for(int j=0;j<=min(i,n/2);j++){
                int k=i-j;
                dp[now][j]=dp[!now][j];
                if(j>0)
                    dp[now][j]=max(dp[now][j],dp[!now][j-1]+A[i].a);
                if(k>0)
                    dp[now][j]=max(dp[now][j],dp[!now][j]+A[i].b);
            }
            now=!now;
        }
        int ans=-1;
        cout<<dp[!now][n/2]<<endl;
        return;
    }
    bool now=0;
    vector<vector<vector<int>>>dp(2,vector<vector<int>>(n/2+1,vector<int>(n/2+1,0)));
    for(int i=1;i<=n;i++){
        for(int j=0;j<=min(i,n/2);j++)
            for(int k=0;k<=min(i,n/2);k++){
                    int l=i-j-k;
                    if(l>n/2)
                        continue;
                    dp[now][j][k]=dp[!now][j][k];
                    if(j>0)
                        dp[now][j][k]=max(dp[now][j][k],dp[!now][j-1][k]+A[i].a);
                    if(k>0)
                        dp[now][j][k]=max(dp[now][j][k],dp[!now][j][k-1]+A[i].b);
                    if(l>0)
                        dp[now][j][k]=max(dp[now][j][k],dp[!now][j][k]+A[i].c);
            }
        now=!now;
    }
    int ans=-1;
    for(int j=0;j<=n/2;j++)
        for(int k=0;k<=n/2;k++)
            ans=max(ans,dp[!now][j][k]);
    cout<<ans<<endl;
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T=1;
    cin>>T;
    while(T--)
        solve();
    return 0;
}