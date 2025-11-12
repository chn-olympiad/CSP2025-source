//2025CSP-S RP++
#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
#define N 100003
using namespace std;
struct ps
{
    int v[4];
}q[N];
int t,n,s,sz[10];
int ans,fin;
void dg(int x)
{
	if(x==n+1)
	{
		fin=max(fin,ans);
		return ;
	}
	for(int i=1;i<=3;i++)
	{
		if(sz[i]>=n/2) continue;
		//if(q[x].v[i]==0) continue;
		sz[i]++;
		ans+=q[x].v[i];
		dg(x+1);
		sz[i]--;
		ans-=q[x].v[i];
	}
	return ;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
    	fin=ans=0;
        sz[1]=sz[2]=sz[3]=0;
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
        {
            int a,b,c;
            scanf("%d%d%d",&q[i].v[1],&q[i].v[2],&q[i].v[3]);
//            a[i].id=b[i].id=c[i].id=i;
//            q[++s].v=a;
//            q[s].id=i;
//            q[s].h=1;
//            q[++s].v=b;
//            q[s].id=i;
//            q[s].h=2;
//            q[++s].v=c;
//            q[s].id=i;
//            q[s].h=3;
        }
//        for(int i=1;i<=s;i++)
//        {
//            if(vis[q[i].id]) continue;
//            if(sz[q[i].h]>=n/2) continue;
//            ans+=q[i].v;
//            vis[q[i].id]=1;
//            sz[q[i].h]++;
//        }
		dg(1);
        printf("%d\n",fin);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
