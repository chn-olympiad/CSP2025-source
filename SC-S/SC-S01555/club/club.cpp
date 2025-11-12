#include<bits/stdc++.h>
using namespace std;

int T,n,a[100001][3],cnt[3],p[100001];
vector<int>s;

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>T;
    while(T--)
    {
        int ans=0;
        cin>>n;
        s.clear();
        cnt[0]=cnt[1]=cnt[2]=0;
        for(int i=1;i<=n;i++)
        {
            p[i]=0;
            for(int j=0;j<3;j++)
                cin>>a[i][j],
                p[i]=(a[i][p[i]]<a[i][j])?j:p[i];
            ans+=a[i][p[i]];
            ++cnt[p[i]];
        }
        if(cnt[0]*2<=n&&cnt[1]*2<=n&&cnt[2]*2<=n)
        {
            cout<<ans<<"\n";
            continue;
        }
        int t=0,x=0;
        for(int i=0;i<3;i++)
            if(cnt[i]*2>n)
                t=i,
                x=cnt[i];
        for(int i=1;i<=n;i++)
        {
            if(p[i]!=t)
                continue;
            int Max=0;
            for(int j=0;j<3;j++)
                if(j!=t)
                    Max=max(Max,a[i][j]);
            s.push_back(a[i][t]-Max);
        }
        x-=n>>1;
        sort(s.begin(),s.end());
        for(int i=0;i<x&&i<s.size();i++)
            ans-=s[i];
        cout<<ans<<"\n";
    }
}