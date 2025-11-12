#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,c[505],ans;
string s;
const ll mod=998244353;
int dp[20][300050];
vector<int> vt[20];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    // cerr<<(1<<18);
    scanf("%d%d",&n,&m);
    cin>>s;
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    sort(c+1,c+n+1);
    dp[0][0]=1;
    for(int st=0;st<=(1<<n)-1;st++){
        int num=0;
        for(int k=1;k<=n;k++){
            if(st&(1<<k-1)) num++;
        }
        vt[num].push_back(st);
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++){
            for(int st:vt[i-1]){
                for(int k=1;k<=n;k++){
                    if(!(st&(1<<k-1))){

                        if(s[i-1]=='1'&&c[k]>j) dp[j][st+(1<<k-1)]+=dp[j][st];
                        else dp[j+1][st+(1<<k-1)]+=dp[j][st];
                    }
                }
            }
        }
    }
    // cerr<<dp[0][1];
    for(int i=0;i<=n-m;i++){
        ans+=dp[i][(1<<n)-1]; ans%=mod;
    }
    cout<<ans;

}