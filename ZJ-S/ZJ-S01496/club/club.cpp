#include<bits/stdc++.h>
using namespace std;
const long long INF=0x7fffffffffffffff;
struct node
{
    long long data;
    int n,id;
    bool operator<(const node&x)const
        {return x.data<data;}
};
inline long long read()
{
    char c=getchar();
    while (c<48||c>57)
        c=getchar();
    long long ans=0;
    while (c>47&&c<58)
        ans=ans*10+c-48,c=getchar();
    return ans;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T=read();
    while (T--)
    {
        int n=read();
        vector<vector<long long>>a(n+1,vector<long long>(3,0));
        vector<int>t(n+1,0),cnt(3,0);
        vector<priority_queue<node>>q(3);
        long long ans=0;
        for (int i=1;i<=n;++i)
        {
            long long maxn=0;
            for (int j=0;j<3;++j)
            {
                a[i][j]=read();
                if (a[i][j]>maxn)
                    maxn=a[i][j],t[i]=j;
            }
            for (int j=0;j<3;++j)
            	if (t[i]!=j)
                	q[j].push((node){maxn-a[i][j],i,t[i]});
            ans+=maxn;
            cnt[t[i]]++;
        }
        const int mid=n>>1;
        vector<bool>f(n+1,false);
        while (max({cnt[0],cnt[1],cnt[2]})>mid)
        {
            int v=0,u=0,who=0;
            long long minn=INF;
            for (int j=0;j<3;++j)
            	if (cnt[j]<mid)
	            {
	                node s=q[j].top();
                    while (f[s.n]||cnt[s.id]<=mid)
                        q[j].pop(),s=q[j].top();
	                if (s.data<minn)
	                    minn=s.data,v=j,u=s.id,who=s.n;
	            }
		    q[v].pop();
            ans-=minn;
            cnt[u]--;
            cnt[v]++;
            f[who]=true;
        }
        printf("%lld\n",ans);
    }
    return 0;
}