// #define NDEBUG
#include<bits/stdc++.h>
#define For(i,j,k) for(int i=(j);i<=(k);i++)
#define ForD(i,j,k) for(int i=(j);i>=(k);i--)
#define int long long
#define endl '\n'
using namespace std;
bool Mbe;
const int N=505,mod=998244353;
void Add(int &x,int y){x+=y; if(x>=mod) x-=mod;}
int add(int x,int y){x+=y; if(x>=mod) x-=mod; return x;}
int s[N],c[N],cnt[N],pre[N];
int dp[2][N][N];
int C[N][N],frc[N],F[N][N];
void solve(){
    int n,m; cin>>n>>m;
    frc[0]=1;
    For(i,1,n) frc[i]=frc[i-1]*i%mod;
    C[0][0]=1;
    For(i,1,n){
        C[i][0]=1;
        For(j,1,i) C[i][j]=add(C[i-1][j-1],C[i-1][j]);
    }
    For(i,0,n) For(j,0,i) F[i][j]=C[i][j]*frc[j]%mod;
    For(i,1,n){
        char x; cin>>x;
        s[i]=x-'0';
    }
    For(i,1,n){
        cin>>c[i];
        cnt[c[i]]++;
    }
    pre[0]=cnt[0];
    For(i,1,n) pre[i]=cnt[i]+pre[i-1];
    int c=0;
    dp[0][0][0]=1;
    For(i,1,n){
        int o=c; c^=1;
        memset(dp[c],0,sizeof dp[c]);
        if(s[i]==1){
            For(j,0,i-1) For(k,0,i-1) if(dp[o][j][k]) Add(dp[c][j+1][k+1],dp[o][j][k]);
            For(j,0,i-1) For(k,0,i-1) if(dp[o][j][k]){
                int v=i-1-j;
                For(d,0,min(cnt[v+1],k)){
                    Add(dp[c][j][k-d],dp[o][j][k]*F[cnt[v+1]][d]%mod*max(0ll,pre[v]-(i-1-k))%mod*C[k][d]%mod);
                }
            }
        }else{
            For(j,0,i-1) For(k,0,i-1) if(dp[o][j][k]){
                int v=i-1-j;
                For(d,0,min(cnt[v+1],k+1)){
                    // if(i==2&&j==1&&k+1-d==0) cerr<<j<<' '<<k<<' '<<dp[o][j][k]<<' '<<cnt[v+1]<<endl;
                    Add(dp[c][j][k+1-d],dp[o][j][k]*F[cnt[v+1]][d]%mod*C[k+1][d]%mod);
                }
            }
            For(j,0,i-1) For(k,0,i-1) if(dp[o][j][k]){
                int v=i-1-j;
                For(d,0,min(cnt[v+1],k)){
                    // if(i==2&&j==1&&k-d==0) cerr<<j<<' '<<k<<' '<<dp[o][j][k]<<' '<<cnt[v+1]<<endl;
                    Add(dp[c][j][k-d],dp[o][j][k]*F[cnt[v+1]][d]%mod*max(0ll,pre[v]-(i-1-k))%mod*C[k][d]%mod);
                }
            }
        }
        // if(i==2) cerr<<' '<<dp[c][2][2]<<endl;
    }
    // cerr<<dp[c][2][1]<<endl;
    int ans=0;
    For(i,m,n) For(j,0,n){
        if(n-j==pre[n-i]) Add(ans,dp[c][i][j]*frc[j]%mod);
    }
    cout<<ans<<endl;
}
bool Med;
signed main(){
    fprintf(stderr,"%.3lf MB\n",(&Mbe-&Med)/1048576.0);
    freopen("employ.in","r",stdin), freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0),cout.tie(0);
    int _=1;
    // cin>>_;
    while(_--) solve();
    cerr<<1e3*clock()/CLOCKS_PER_SEC<<" ms\n";
    return 0;
}
/*
3 2
111
1 2 0
*/