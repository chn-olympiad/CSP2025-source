#include<bits/stdc++.h>
using namespace std;

int t,n,d1[100005],d2[100005],d3[100005],p1,p2,p3;
struct node
{
    int a;
    int b;
    int c;
}x[200005];

bool cmp(node p,node q)
{
    if(p.a!=q.a)return p.a>q.a;
    if(p.b!=q.b)return p.b>q.b;
    return p.c>q.c;
}

void zd()
{
    p1=0,p2=0,p3=0;
    for(int i=1;i<=n;i++)
    {
        if(x[i].a>=x[i].b&&x[i].a>=x[i].c&&p1<n/2)
        {
            p1++;
            d1[p1]=i;
        }
        else if(x[i].b>=x[i].c&&p2<n/2)
        {
            p2++;
            d2[p2]=i;
        }
        else
        {
            p3++;
            d3[p3]=i;

        }
    }
    for(int i=1;i<=p1;i++)
    {
        for(int j=1;j<=p2;j++)
        {
            if(x[d1[i]].a+x[d2[j]].b<x[d1[i]].b+x[d2[j]].a)
            {
                int s=d1[i];
                d1[i]=d2[j];
                d2[j]=s;
            }
        }
    }
    for(int i=1;i<=p1;i++)
    {
        for(int j=1;j<=p3;j++)
        {
            if(x[d1[i]].a+x[d3[j]].c<x[d1[i]].c+x[d3[j]].a)
            {
                int s=d1[i];
                d1[i]=d3[j];
                d3[j]=s;
            }
        }
    }
    for(int i=1;i<=p3;i++)
    {
        for(int j=1;j<=p2;j++)
        {
            if(x[d3[i]].c+x[d2[j]].b<x[d3[i]].b+x[d2[j]].c)
            {
                int s=d3[i];
                d3[i]=d2[j];
                d2[j]=s;
            }
        }
    }
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		long long ans=0;
		for(int i=1;i<=n;i++)
        {
            cin>>x[i].a>>x[i].b>>x[i].c;
        }
        sort(x+1,x+n+1,cmp);
        zd();
        for(int i=1;i<=p1;i++)
        {
            ans+=x[d1[i]].a;
        }
        for(int i=1;i<=p2;i++)
        {
            ans+=x[d2[i]].b;
        }
        for(int i=1;i<=p3;i++)
        {
            ans+=x[d3[i]].c;
        }
        cout<<ans<<endl;
	}
    return 0;
}
