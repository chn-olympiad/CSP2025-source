#include <bits/stdc++.h>
using namespace std;
const int N=1e5+50;
typedef long long ll;
ll t,n,dp[N][5],m[5],mm[N][5],ans1;
struct member{
    ll x,y,z;
}a[N];
bool cmp(member a,member b){
    if(a.x!=b.x) return a.x>b.x;
    if(a.y!=b.y) return a.y>b.y;
    return a.z>b.z;
}
void dfs(ll depth,ll c,ll cnt){
    if(c==1) cnt+=a[depth].x;
    if(c==2) cnt+=a[depth].y;
    if(c==3) cnt+=a[depth].z;
    if(depth==n){
        ans1=max(ans1,cnt);
        return;
    }
    if(m[1]<n/2){
        m[1]++;
        dfs(depth+1,1,cnt);
        m[1]--;
    }
    if(m[2]<n/2){
        m[2]++;
        dfs(depth+1,2,cnt);
        m[2]--;
    }
    if(m[3]<n/2){
        m[3]++;
        dfs(depth+1,3,cnt);
        m[3]--;
    }
    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        bool flag=true;
        ans1=0;
        memset(dp,-1,sizeof(dp));
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
            if(a[i].y!=0||a[i].z!=0) flag=false;
        }
        if(n<=10){
            dfs(0,1,0);
            cout<<ans1<<endl;
            continue;
        }else if(flag){
            sort(a+1,a+1+n,cmp);
            for(int i=1;i<=n/2;i++) ans1+=a[i].x;
            cout<<ans1<<endl;
            continue;
        }
        dp[0][1]=0;dp[0][2]=0;dp[0][3]=0;
        mm[0][1]=mm[0][2]=mm[0][3]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                if(mm[i][j]>=n/2) dp[i][j]=dp[i-1][j];
                else{
                    if(j==1){
                        dp[i][1]=max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]))+a[i].x;
                        if(dp[i][1]==dp[i-1][1]+a[i].x) mm[i][1]=mm[i-1][1]+1;
                        else if(dp[i][1]==dp[i-1][2]+a[i].x) mm[i][2]=mm[i-1][2]+1;
                        else if(dp[i][1]==dp[i-1][3]+a[i].x) mm[i][3]=mm[i-1][3]+1;
                    }
                    if(j==2){
                        dp[i][2]=max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]))+a[i].y;
                        if(dp[i][2]==dp[i-1][2]+a[i].y) mm[i][2]=mm[i-1][2]+1;
                        else if(dp[i][2]==dp[i-1][1]+a[i].y) mm[i][1]=mm[i-1][1]+1;
                        else if(dp[i][2]==dp[i-1][3]+a[i].y) mm[i][3]=mm[i-1][3]+1;
                    }
                    if(j==3){
                        dp[i][3]=max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]))+a[i].z;
                        if(dp[i][3]==dp[i-1][3]+a[i].z) mm[i][3]=mm[i-1][3]+1;
                        else if(dp[i][3]==dp[i-1][1]+a[i].z) mm[i][1]=mm[i-1][1]+1;
                        else if(dp[i][3]==dp[i-1][2]+a[i].z) mm[i][2]=mm[i-1][2]+1;
                    }
                }
            }
        }
        cout<<max(dp[n][1],max(dp[n][2],dp[n][3]))<<endl;
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
