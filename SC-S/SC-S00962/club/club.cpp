





#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long ll;
template <typename T> void read(T& num){
    num=0;bool sign=false;
    char ch=getchar();
    while(ch<'0'||ch>'9') sign=(ch=='-'),ch=getchar();
    while('0'<=ch&&ch<='9') num=(num<<1)+(num<<3)+(ch-'0'),ch=getchar();
    num=sign?~(num-1):num;
}
ll read(){
    ll num=0;bool sign=false;
    char ch=getchar();
    while(ch<'0'||ch>'9') sign=(ch=='-'),ch=getchar();
    while('0'<=ch&&ch<='9') num=(num<<1)+(num<<3)+(ch-'0'),ch=getchar();
    return sign?~(num-1):num;
}
const int MAXN=1e5+8;
const ll NEG=0xc0c0c0c0c0c0c0c0;
int n,m;
ll a[MAXN][5];
struct st{
    ll data=NEG;
    int cnts[4]={0,0,0,0};
    st operator+(ll a) {
        st temp=*this;
        temp.data+=a;
        return temp;
    }
    const bool operator<(const st& rhs) const {
        return data<rhs.data;
    }
    st ad(short i){
        cnts[i]++;
        return *this;
    }
    int sm(){
        return cnts[1]+cnts[2]+cnts[3];
    }
} dp[MAXN][5];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    read(T);
    while(T--){
        read(n);
        // memset(dp,NEG,sizeof(dp));
        for(int i=1;i<=n;i++) // read
            for(int j=1;j<=3;j++)
                read(a[i][j]),dp[i][j]={};
        dp[0][1].data=dp[0][2].data=dp[0][3].data=0;
        ll ans=NEG;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                for(int k=0;k<=i;k++){
                    // can choose?
                    dp[i][j]=max(max((
                            dp[k][1].cnts[j]<n/2&&dp[k][1].sm()<i+(j==1)?(dp[k][1]+a[i][j]).ad(j):dp[i][j]),dp[i][j]),max((
                            dp[k][2].cnts[j]<n/2&&dp[k][2].sm()<i+(j==2)?(dp[k][2]+a[i][j]).ad(j):dp[i][j]),(
                            dp[k][3].cnts[j]<n/2&&dp[k][3].sm()<i+(j==3)?(dp[k][3]+a[i][j]).ad(j):dp[i][j])));
                    ans=max(ans,dp[i][j].data);
                }
            }
        }
        cout<<(ans==NEG?0:ans)<<"\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

