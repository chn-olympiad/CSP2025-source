#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int a[1000010][4];
int num[4];
int op[1000010];
int val[1000010];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        long long ans=0;
        scanf("%d",&n),num[1]=num[2]=num[3]=0;
        for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
        for(int i=1;i<=n;i++)
        {
            if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) ans+=a[i][1],op[i]=1;
            else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]) ans+=a[i][2],op[i]=2;
            else ans+=a[i][3],op[i]=3;
            num[op[i]]++;
        }
        int tot=0;
        for(int now=1;now<=3;now++) if(num[now]>(n>>1))
        {
            for(int i=1;i<=n;i++) if(op[i]==now)
            {
                int mx=0;
                for(int j=1;j<=3;j++) if(j!=now) mx=max(mx,a[i][j]);
                val[++tot]=a[i][now]-mx;
            }
        }
        sort(val+1,val+tot+1);
        for(int i=1;i<=tot-(n>>1);i++) ans-=val[i];
        printf("%lld\n",ans);
    }
}