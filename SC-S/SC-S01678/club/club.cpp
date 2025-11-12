#include<cstdio>
#include<cctype>
#include<algorithm>
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
using namespace std;
char buf[1<<20],*p1=buf,*p2=buf;
template<typename type>
inline void read(type &x)
{
    x=0;
    bool flag=0;char ch=gc();
    while(!isdigit(ch)) flag=ch=='-',ch=gc();
    while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=gc();
    flag?x=-x:0;
}
typedef long long ll;
const int MAXN=1e5+10;
int T,n,a[MAXN][4],b[MAXN],cnt[4],bl[MAXN],nx[4][2];
ll ans;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    read(T);
    nx[1][0]=2,nx[1][1]=3,nx[2][0]=3,nx[2][1]=1,nx[3][0]=1,nx[3][1]=2;
    while(T--)
    {
        read(n);
        ans=cnt[1]=cnt[2]=cnt[3]=0;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=3;++j) read(a[i][j]);
            if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) cnt[1]++,bl[i]=1,ans+=a[i][1];
            else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]) cnt[2]++,bl[i]=2,ans+=a[i][2];
            else cnt[3]++,bl[i]=3,ans+=a[i][3]; 
        } 
        for(int t=1;t<=3;++t)
        {
            if(cnt[t]>n/2)
            {;
                int tot=0;
                for(int i=1;i<=n;++i)
                {
                    if(bl[i]==t)
                    {
                        b[++tot]=max(a[i][nx[t][0]]-a[i][t],a[i][nx[t][1]]-a[i][t]);
                    }
                }
                sort(b+1,b+tot+1);
                for(int i=n/2+1;i<=tot;++i)
                {
                    ans+=1ll*b[i];
                }
            }
        }
        printf("%lld\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}