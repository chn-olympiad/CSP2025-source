#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,a[N][4],ans;
vector<int> p[4];
void solve()
{
    ans=0;
    p[1].clear(),p[2].clear(),p[3].clear();
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i][1]>>a[i][2]>>a[i][3];
        ans+=max(a[i][1],max(a[i][2],a[i][3]));
        if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
        {
            p[1].push_back(i);
        }
        else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
        {
            p[2].push_back(i);
        }
        else
        {
            p[3].push_back(i);
        }
    }
    if(p[1].size()>n/2)
    {
        sort(p[1].begin(),p[1].end(),[](int x,int y){return min(a[x][1]-a[x][2],a[x][1]-a[x][3])<min(a[y][1]-a[y][2],a[y][1]-a[y][3]);});
        for(int i=0;i<p[1].size()-n/2;i++)
        {
            ans-=min(a[p[1][i]][1]-a[p[1][i]][2],a[p[1][i]][1]-a[p[1][i]][3]);
        }
    }
    else if(p[2].size()>n/2)
    {
        sort(p[2].begin(),p[2].end(),[](int x,int y){return min(a[x][2]-a[x][1],a[x][2]-a[x][3])<min(a[y][2]-a[y][1],a[y][2]-a[y][3]);});
        for(int i=0;i<p[2].size()-n/2;i++)
        {
            ans-=min(a[p[2][i]][2]-a[p[2][i]][1],a[p[2][i]][2]-a[p[2][i]][3]);
        }
    }
    else if(p[3].size()>n/2)
    {
        sort(p[3].begin(),p[3].end(),[](int x,int y){return min(a[x][3]-a[x][1],a[x][3]-a[x][2])<min(a[y][3]-a[y][1],a[y][3]-a[y][2]);});
        for(int i=0;i<p[3].size()-n/2;i++)
        {
            ans-=min(a[p[3][i]][3]-a[p[3][i]][1],a[p[3][i]][3]-a[p[3][i]][2]);
        }
    }
    cout<<ans<<'\n';
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>T;
    while(T--) solve();
}