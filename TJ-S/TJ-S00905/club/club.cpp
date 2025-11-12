#include<bits/stdc++.h>
using namespace std;
const int N=1e5 +10;
int n,m;
int aa[3][N];
struct node{
    int i,b,c;
};
bool operator<(node a,node b)
{
    return min(a.b,a.c)>min(b.b,b.c);
}
priority_queue<node>q[3];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            cin>>aa[0][i]>>aa[1][i]>>aa[2][i];
        }
        for(int i=0;i<n;i++)
        {
            int a=aa[0][i],b=aa[1][i],c=aa[2][i];
            if(a>=b&&a>=c)
            {
                q[0].push({i,a-b,a-c});
                ans+=a;
            }
            else if(b>=a&&b>=c)
            {
                ans+=b;
                q[1].push({i,b-a,b-c});
            }
            else
            {
                q[2].push({i,c-a,c-b});
                ans+=c;
            }
        }
        for(int i=0;i<3;i++)
        while(q[i].size()>n/2)
        {
            node f=q[i].top();
            q[i].pop();
            ans-=min(f.b,f.c);
        }
        cout<<ans<<endl;
        for(int i=0;i<3;i++)
        {
            while(!q[i].empty())
            {
                q[i].pop();
            }
        }
    }
    return 0;
}
