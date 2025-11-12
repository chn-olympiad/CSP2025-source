#include<bits/stdc++.h>
using namespace std;

const int MAXN=205;

int a[100005][4];
int dp[MAXN][MAXN][MAXN];

int main(){
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin>>T;
  while(T--){
    int n;
    cin>>n;
    bool flg=true;
    for(int i=1;i<=n;++i){
      cin>>a[i][1]>>a[i][2]>>a[i][3];
      if(a[i][2]||a[i][3]){
        flg=false;
      }
    }
    if(flg){
      priority_queue<int> h;
      for(int i=1;i<=n;++i){
        h.push(a[i][1]);
      }
      int ans=0;
      for(int i=1;i<=n/2;++i){
        ans+=h.top(); 
      }
      cout<<ans<<"\n";
      continue;
    }
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;++i){
      for(int j=0;j<=i;++j){
        for(int k=0;j+k<=i;++k){
          dp[i+1][j+1][k]=max(dp[i+1][j+1][k],dp[i][j][k]+a[i+1][1]);
          dp[i+1][j][k+1]=max(dp[i+1][j][k+1],dp[i][j][k]+a[i+1][2]);
          dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]+a[i+1][3]);
//          cerr<<"dp["<<i<<"]["<<j<<"]["<<k<<"]="<<dp[i][j][k]<<"\n";
        }
      }
    }
    int ans=0;
    for(int i=0;i<=n/2;++i){
      for(int j=0;j<=n/2;++j){
        if(n-(i+j)<=n/2){
          ans=max(ans,dp[n][i][j]);
        }
      }
    }
    cout<<ans<<"\n";
  }
}

