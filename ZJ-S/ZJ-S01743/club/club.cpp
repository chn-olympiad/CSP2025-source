#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace awa
{
    const int N=1e5;

    int n,a[N+5][5],b[N+5],len;
    int mark[N+5],cnt[5];

    ll ans;
    inline void qwq()
    {
        cin>>n,ans=len=cnt[1]=cnt[2]=cnt[3]=0;
        for(int i=1;i<=n;++i) cin>>a[i][1]>>a[i][2]>>a[i][3];
        for(int i=1;i<=n;++i)
        {
            if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) mark[i]=1;
            else if(a[i][2]>=a[i][3]) mark[i]=2;
            else mark[i]=3;
            ++cnt[mark[i]],ans+=a[i][mark[i]];
        }
        for(int i=1;i<=3;++i)
            if(cnt[i]>n/2)
            {
                for(int j=1;j<=n;++j)
                    if(mark[j]==i) b[++len]=max(a[j][i%3+1],a[j][(i+1)%3+1])-a[j][i];
                sort(b+1,b+len+1);
                for(int j=1;j<=cnt[i]-n/2;++j)
                    ans+=b[len-j+1];
                break;
            }
        cout<<ans<<'\n';
    }
}

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;cin>>T;while(T--) awa::qwq();
    return 0;
}