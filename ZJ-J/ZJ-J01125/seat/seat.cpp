#include<bits/stdc++.h>
using namespace std;
#define int long long 

signed main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    scanf("%lld%lld",&n,&m);
    vector<int>a(n*m+1);
    vector<vector<int>>gra(n+1,vector<int>(m+1));
    for(int i=1;i<=n*m;++i)
    {
        scanf("%lld",&a[i]);
    }
    int a1=a[1];
    sort(a.begin()+1,a.end(),greater<>());
    for(int i=1;i<=m;++i)
    {
        if(i&1)
        {
            for(int j=1;j<=n;++j)
            {
                gra[j][i]=a[(i-1)*n+j];
                if(gra[j][i]==a1)
                {
                    printf("%lld %lld\n",i,j);
                    return 0;
                }
            }
        }
        else
        {
            for(int j=n;j>=1;--j)
            {
                gra[j][i]=a[(i-1)*n+n-j+1];
                if(gra[j][i]==a1)
                {
                    printf("%lld %lld\n",i,j);
                    return 0;
                }
            }
        }
    }

    return 0;
}
