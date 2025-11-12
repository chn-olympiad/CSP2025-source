#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=1e6+10;
constexpr int maxm=1e6+10;

int T;
int n;
int a[maxn][4];
int ans=0;
vector<int> duo;
int goa,gob,goc;

signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&T);
    while(T--)
    {
        goa=0;
        gob=0;
        goc=0;
        ans=0;
        duo.clear();
        scanf("%lld",&n);
        for(int i=1;i<=n;++i)
        {
            scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
            if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
            {
                goa++;
                ans+=a[i][1];
            }
            else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
            {
                gob++;
                ans+=a[i][2];
            }
            else
            {
                goc++;
                ans+=a[i][3];
            }
        }
        if(goa<=n/2&&gob<=n/2&&goc<=n/2)
        {
            printf("%lld\n",ans);
        }
        else if(goa>n/2)
        {
            int more=goa-n/2;
            for(int i=1;i<=n;++i)
            {
                if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
                {
                    duo.push_back(min(a[i][1]-a[i][2],a[i][1]-a[i][3]));
                }
            }
            sort(duo.begin(),duo.end());
            for(int i=0;i<more;++i)
            {
                ans-=duo[i];
            }
            printf("%lld\n",ans);
        }
        else if(gob>n/2)
        {
            int more=gob-n/2;
            for(int i=1;i<=n;++i)
            {
                if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
                {
                    duo.push_back(min(a[i][2]-a[i][1],a[i][2]-a[i][3]));
                }
            }
            sort(duo.begin(),duo.end());
            for(int i=0;i<more;++i)
            {
                ans-=duo[i];
            }
            printf("%lld\n",ans);
        }
        else if(goc>n/2)
        {
            int more=goc-n/2;
            for(int i=1;i<=n;++i)
            {
                if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2])
                {
                    duo.push_back(min(a[i][3]-a[i][2],a[i][3]-a[i][1]));
                }
            }
            sort(duo.begin(),duo.end());
            for(int i=0;i<more;++i)
            {
                ans-=duo[i];
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}

