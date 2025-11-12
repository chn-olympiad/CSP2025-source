#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,w,ans,a[N][5],cnt[5],st[5][N];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        ans=cnt[1]=cnt[2]=cnt[3]=0;
        scanf("%d",&n);
        for(int i=1,s;i<=n;i++)
        {
            s=0;
            for(int j=1;j<=3;j++)
            {
                scanf("%d",&a[i][j]);
                s=max(s,a[i][j]);
            }
            if(a[i][1]==s)st[1][++cnt[1]]=i;
            else if(a[i][2]==s)st[2][++cnt[2]]=i;
            else st[3][++cnt[3]]=i;
            ans+=s;
        }
        w=0;
        if(cnt[1]>n/2)w=1;
        else if(cnt[2]>n/2)w=2;
        else if(cnt[3]>n/2)w=3;
        if(!w)printf("%d\n",ans);
        else
        {
            for(int i=1,s;i<=cnt[w];i++)
            {
                s=0;
                for(int j=1;j<=3;j++)
                {
                    if(j!=w)s=max(s,a[st[w][i]][j]);
                }
                st[w][i]=a[st[w][i]][w]-s;
            }
            sort(st[w]+1,st[w]+1+cnt[w]);
            for(int i=1;i<=cnt[w]-n/2;i++)ans-=st[w][i];
            printf("%d\n",ans);
        }
    }
    return 0;
}