#include<bits/stdc++.h>
using namespace std;
struct node
{
	int a,b,c;
	int maxn;
	int id;
	bool vis;
}p[100005];
int cnt[5];
int n,ans,T;
bool cmp(node x,node y)
{
	return x.maxn>y.maxn;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int tmp[4];
			for(int j=1;j<=3;j++)
			{
			    cin>>tmp[j];
			    if(p[i].maxn<tmp[j])
			    {
			    	p[i].maxn=tmp[j];
			    	p[i].id=j;
				}
			}
			p[i].a=tmp[1];
			p[i].b=tmp[2];
			p[i].c=tmp[3];
		}
		sort(p+1,p+1+n,cmp);
		int tot=0;
		for(int i=1;i<=n;i++)
		{
			if(cnt[p[i].id]<n/2)
			{
				ans+=p[i].maxn;
				p[i].vis=true;
				cnt[p[i].id]++;
			}
			else
			{
				tot=p[i].id;
				break;
			}
		}
		if(tot==0)
		{
			cout<<ans<<endl;
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
			    p[i].maxn=-1; 
			    if(!p[i].vis)
				{	
					int tmp[5];
					tmp[1]=p[i].a;
					tmp[2]=p[i].b;
					tmp[3]=p[i].c;
					for(int j=1;j<=3;j++)
					{
						if(j!=tot)
						{
							if(p[i].maxn<tmp[j])
							{
								p[i].maxn=tmp[j];
								p[i].id=j;
							}
						}
					}
				}
	    	}
		    sort(p+1,p+1+n,cmp);
		    int i=1;
		    while(p[i].maxn!=-1)
		    {
		    	ans+=p[i].maxn;
		    	i++;
			}
			cout<<ans<<endl;
		}
		for(int i=1;i<=n;i++)
		{
			p[i].maxn=0;
			p[i].a=0;
			p[i].b=0;
			p[i].c=0;
			p[i].id=0; 
			p[i].vis=false;
		}
		for(int i=1;i<=3;i++)
		{
			cnt[i]=0;
		}
		ans=0;
    }
	return 0;
} 
