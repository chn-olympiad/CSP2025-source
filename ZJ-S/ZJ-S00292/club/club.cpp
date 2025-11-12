#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+55;

int n;
ll a[N][5];
ll dp[205][205][205][2];

void te1(){
    ll ans=0;
    int op=0;
    for(int i=0;i<n;i++){
        op^=1;
        for(int j=0;j<=min(n/2,i);j++){//1
            for(int k=0;k+j<=i&&k<=min(n/2,i);k++){//2
                int l=i-j-k;//3
                if(l>n/2||l>i||l<0) continue;
                dp[j+1][k][l][op^1]=max(dp[j+1][k][l][op^1],dp[j][k][l][op]+a[i+1][1]);
                dp[j][k+1][l][op^1]=max(dp[j][k+1][l][op^1],dp[j][k][l][op]+a[i+1][2]);
                dp[j][k][l+1][op^1]=max(dp[j][k][l+1][op^1],dp[j][k][l][op]+a[i+1][3]);
            }
        }
    }
    for(int i=0;i<=n/2;i++) for(int j=0;j<=n/2&&i+j<=n;j++){
        int k=n-i-j;
        if(k>n/2) continue;
        ans=max(ans,dp[i][j][k][op^1]);
    }
    cout<<ans<<"\n";
    for(int i=0;i<=n+1;i++) for(int j=0;j<=n+1;j++) for(int k=0;k<=n+1;k++) dp[i][j][k][1]=dp[i][j][k][0]=0;
}

bool checka(){
    for(int i=1;i<=n;i++){
        if(a[i][2]!=0||a[i][3]!=0) return false;
    }
    return true;
}
void tea(){
    vector<ll> xx(n+1,0);
    for(int i=1;i<=n;i++) xx[i]=a[i][1];
    sort(xx.begin(),xx.end());
    ll ans=0;
    for(int i=n;i>n/2;i--) ans+=xx[i];
    cout<<ans<<"\n";
}
struct node{
    ll now;
    int bm;
    int id;
    friend bool operator<(node a,node b){
        return a.now>b.now;
    }
}x[N<<2];
bool visi[N];
int num[5];
int cnt;
void teb(){
    cnt=0;
    ll ans=0;
    ll xx;
    for(register int i=1;i<=n;i++) for(register int j=1;j<=3;j++) cin>>xx,x[++cnt]={xx,j,i};
    sort(x+1,x+cnt+1);
    for(register int i=1;i<=cnt;i++){
        if(visi[x[i].id]) continue;
        if(num[x[i].bm]>=n/2) continue;
        ans+=x[i].now;
        visi[x[i].id]=1;
        num[x[i].bm]++;
    }
    cout<<ans<<"\n";
    for(register int i=0;i<=n;i++) visi[i]=0;
    num[0]=num[1]=num[2]=num[3]=0;
}

void solve(){
    cin>>n;
    if(n>200) return teb();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=3;j++){
            cin>>a[i][j];
        }
    if(checka()) return tea();
    if(n<=200)
        return te1();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int _T=1;
    cin>>_T;
    while(_T--) solve();
    return 0;
}