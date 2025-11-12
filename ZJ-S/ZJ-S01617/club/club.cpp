#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=1e5+10;
int a[maxn][4],a1[maxn][4],a2[maxn][4],a3[maxn][4];
int dp[maxn];
int flag[maxn][4];
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    int T;
    scanf("%lld",&T);
    while(T--)
    {
        int n;
        scanf("%lld",&n);
        for(int i=1;i<=n;++i)
        {
            scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
            dp[i]=0;
            flag[i][1]=0;
            flag[i][2]=0;
            flag[i][3]=0;
            a1[i][1]=0;
            a2[i][2]=0;
            a3[i][3]=0;
        }
        int cnt1=0;
        int cnt2=0;
        int cnt3=0;
        int bef=0;
        int f=0;
        int s1=0;
        int s2=0;
        int q1=0;
        int q2=0;
        for(int i=1;i<=n;++i)
        {
            if(cnt1<n/2&&cnt2<n/2&&cnt3<n/2)
            {
                bef=dp[i];
                f=0;
                dp[i]=max(dp[i],a[i][1]+dp[i-1]);
                if(dp[i]!=bef) f=1;
                bef=dp[i];
                dp[i]=max(dp[i],a[i][2]+dp[i-1]);
                if(dp[i]!=bef) f=2;
                bef=dp[i];
                dp[i]=max(dp[i],a[i][3]+dp[i-1]);
                if(dp[i]!=bef) f=3;
                if(f==1) cnt1++,a1[cnt1][1]=a[i][1],a1[cnt1][2]=a[i][2],a1[cnt1][3]=a[i][3];
                if(f==2) cnt2++,a2[cnt2][1]=a[i][1],a2[cnt2][2]=a[i][2],a2[cnt2][3]=a[i][3];
                if(f==3) cnt3++,a3[cnt3][1]=a[i][1],a3[cnt3][2]=a[i][2],a3[cnt3][3]=a[i][3];

            }
            else if(cnt1>=n/2&&cnt2<n/2&&cnt3<n/2)
            {
                s1=-50000;
                s2=-50000;
                f=0;
                q1=0,q2=0;
                for(int j=1;j<=cnt1;++j)
                {
                    if(flag[j][1]==1) continue;
                    bef=s1;
                    s1=max(s1,a1[j][2]-a1[j][1]);
                    if(s1!=bef) q1=j;
                    bef=s2;
                    s2=max(s2,a1[j][3]-a1[j][1]);
                    if(s2!=bef) q2=j;
                }
                bef=dp[i];
                dp[i]=max(dp[i],a[i][2]+dp[i-1]);
                if(dp[i]!=bef) f=2;
                bef=dp[i];
                dp[i]=max(dp[i],a[i][3]+dp[i-1]);
                if(dp[i]!=bef) f=3;
                bef=dp[i];
                dp[i]=max(dp[i],a[i][1]+s1+dp[i-1]);
                if(dp[i]!=bef) f=5;
                bef=dp[i];
                dp[i]=max(dp[i],a[i][1]+s2+dp[i-1]);
                if(dp[i]!=bef) f=6;
                if(f==2||f==5) cnt2++,a2[cnt2][1]=a[i][1],a2[cnt2][2]=a[i][2],a2[cnt2][3]=a[i][3];
                if(f==3||f==6) cnt3++,a3[cnt3][1]=a[i][1],a3[cnt3][2]=a[i][2],a3[cnt3][3]=a[i][3];
                if(f==5) flag[q1][1]=1;
                if(f==6) flag[q2][1]=1;
            }
            else if(cnt1<n/2&&cnt2>=n/2&&cnt3<n/2)
            {
                s1=-50000;
                s2=-50000;
                f=0;
                q1=0,q2=0;
                for(int j=1;j<=cnt2;++j)
                {
                    if(flag[j][2]==1) continue;
                    bef=s1;
                    s1=max(s1,a2[j][1]-a2[j][2]);
                    if(s1!=bef) q1=j;
                    bef=s2;
                    s2=max(s2,a2[j][3]-a2[j][2]);
                    if(s2!=bef) q2=j;
                }
                bef=dp[i];
                dp[i]=max(dp[i],a[i][1]+dp[i-1]);
                if(dp[i]!=bef) f=1;
                bef=dp[i];
                dp[i]=max(dp[i],a[i][3]+dp[i-1]);
                if(dp[i]!=bef) f=3;
                bef=dp[i];
                dp[i]=max(dp[i],a[i][2]+s1+dp[i-1]);
                if(dp[i]!=bef) f=4;
                bef=dp[i];
                dp[i]=max(dp[i],a[i][2]+s2+dp[i-1]);
                if(dp[i]!=bef) f=6;
                if(f==1||f==4) cnt1++,a1[cnt1][1]=a[i][1],a1[cnt1][2]=a[i][2],a1[cnt1][3]=a[i][3];
                if(f==3||f==6) cnt3++,a3[cnt3][1]=a[i][1],a3[cnt3][2]=a[i][2],a3[cnt3][3]=a[i][3];
                if(f==4) flag[q1][2]=1;
                if(f==6) flag[q1][2]=1;
            }
            else if(cnt1<n/2&&cnt2<n/2&&cnt3>=n/2)
            {
                s1=-50000;
                s2=-50000;
                f=0;
                q1=0,q2=0;
                for(int j=1;j<=cnt3;++j)
                {
                    if(flag[j][3]==1) continue;
                    bef=s1;
                    s1=max(s1,a3[j][1]-a3[j][3]);
                    if(s1!=bef) q1=j;
                    bef=s2;
                    s2=max(s2,a3[j][2]-a3[j][3]);
                    if(s2!=bef) q2=j;
                }
                bef=dp[i];
                dp[i]=max(dp[i],a[i][1]+dp[i-1]);
                if(dp[i]!=bef) f=1;
                bef=dp[i];
                dp[i]=max(dp[i],a[i][2]+dp[i-1]);
                if(dp[i]!=bef) f=2;
                bef=dp[i];
                dp[i]=max(dp[i],a[i][3]+s1+dp[i-1]);
                if(dp[i]!=bef) f=4;
                bef=dp[i];
                dp[i]=max(dp[i],a[i][3]+s2+dp[i-1]);
                if(dp[i]!=bef) f=5;
                if(f==1||f==4) cnt1++,a1[cnt1][1]=a[i][1],a1[cnt1][2]=a[i][2],a1[cnt1][3]=a[i][3];
                if(f==2||f==5) cnt2++,a2[cnt2][1]=a[i][1],a2[cnt2][2]=a[i][2],a2[cnt2][3]=a[i][3];
                if(f==4) flag[q1][3]=1;
                if(f==5) flag[q1][3]=1;
            }
        }
        printf("%lld\n",dp[n]);
    }

    return 0;
}
