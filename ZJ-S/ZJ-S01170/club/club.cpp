#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=1e5+10;

struct pf
{
    int a,b,c,id;
    pf()=default;
    pf(int a,int b,int c,int id):a(a),b(b),c(c),id(id){}
    bool operator<(const pf&o)const
    {
        vector<pair<int,int>>zj(3),br(3);
        zj[0]={a,1},zj[1]={b,2},zj[2]={c,3};
        br[0]={o.a,1},br[1]={o.b,2},br[2]={o.c,3};
        sort(zj.begin(),zj.end(),greater<>()),sort(br.begin(),br.end(),greater<>());
        return zj[0].first-zj[1].first<br[0].first-br[1].first;
    

    }
};
vector<pair<int,int>> pm(const pf&a)
{
    vector<pair<int,int>>sm(4);
    sm[1]={a.a,1},sm[2]={a.b,2},sm[3]={a.c,3};
    sort(sm.begin()+1,sm.end(),greater<>());
    return sm;
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%lld",&t);
    while(t--)
    {
        int n,ans=0;
        scanf("%lld",&n);
        vector<int>cnt(4);
        priority_queue<pf>q;
        vector<pair<int,int>>big(n+1),mid(n+1);
        for(int i=1;i<=n;++i)
        {
            int a,b,c;
            scanf("%lld%lld%lld",&a,&b,&c);
            pf k=pf(a,b,c,i);
            vector<pair<int,int>>sss=pm(k);
            big[i].first=sss[1].first;
            big[i].second=sss[1].second;
            mid[i].first=sss[2].first;
            mid[i].second=sss[2].second;
            q.emplace(a,b,c,i);
        }
        // if(n<=20)
        // {
        //     for(int o=0;o<=(1<<n)-1;++o)
        //     {
        //         int tmp=0;
        //         cnt[1]=cnt[2]=cnt[3]=0;
        //         for(int i=1;i<=n;++i)
        //         {
        //             if((o>>(i-1))&1)
        //             {
        //                 tmp+=big[i].first;
        //                 ++cnt[big[i].second];
        //                 if(cnt[big[i].second]>n/2)
        //                 {
        //                     goto aaaa;
        //                 }
        //             }
        //             else
        //             {
        //                 tmp+=mid[i].first;
        //                 ++cnt[mid[i].second];
        //                 if(cnt[mid[i].second]>n/2)
        //                 {
        //                     goto aaaa;
        //                 }
        //             }
        //         }
        //         ans=max(ans,tmp);
        //         aaaa:;
        //     }
        //     printf("%lld\n",ans);
        // }
        // else
        {
            while(!q.empty())
            {
                pf k=q.top();
                q.pop();
                vector<pair<int,int>>pai=pm(k);
                if(cnt[pai[1].second]<n/2)
                {
                    ++cnt[pai[1].second];
                    ans+=pai[1].first;
                }
                else if(cnt[pai[2].second]<n/2)
                {
                    ++cnt[pai[2].second];
                    ans+=pai[2].first;
                }
                else
                {
                    ++cnt[pai[3].second];
                    ans+=pai[3].first;
                }
            }
            printf("%lld\n",ans);
        }
    }


    return 0;
}
