#include <bits/stdc++.h>
using namespace std;
int t,n,maxp[50001][4],maxq[50001][4],maxr[50001][4];
struct node
{
	int p,q,r,bh;
	int bj;
}a[100001];
bool cmpp(node x,node y)
{
	if(x.p==y.p)
	{
		if(x.q==y.q)
		{
			return x.r>y.r;
		}
		return x.q>y.q;
	}
	return x.p>y.p;
}
bool cmpq(node x,node y)
{
	if(x.q==y.q)
	{
		if(x.p==y.p)
		{
			return x.r>y.r;
		}
		return x.p>y.p;
	}
	return x.q>y.q;
}
bool cmpr(node x,node y)
{
	if(x.r==y.r)
	{
		if(x.p==y.p)
		{
			return x.q>y.q;
		}
		return x.p>y.p;
	}
	return x.r>y.r;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].p>>a[i].q>>a[i].r;
			a[i].bh=i;
			a[i].bj=1;
	    }
	    sort(a+1,a+n+1,cmpp);
	    for(int i=1;i<=n/2;i++)
	    {
	    	maxp[i][1]=a[i].bh;
	    	maxp[i][2]=a[i].p;
	    	maxp[i][3]=a[i].bj;
		}
		sort(a+1,a+n+1,cmpq);
	    for(int i=1;i<=n/2;i++)
	    {
	    	maxq[i][1]=a[i].bh;
	    	maxq[i][2]=a[i].q;
	    	maxq[i][3]=a[i].bj;
		}
		sort(a+1,a+n+1,cmpr);
	    for(int i=1;i<=n/2;i++)
	    {
	    	maxr[i][1]=a[i].bh;
	    	maxr[i][2]=a[i].r;
	    	maxr[i][3]=a[i].bj;
		}
		int ans=0;
		for(int i=1;i<=n/2;i++)
		{
			for(int j=1;j<=n/2;j++)
			{
				for(int k=1;k<=n/2;k++)
				{
					if((maxp[i][1]==maxq[j][1]||maxp[i][1]==maxr[k][1]||maxq[j][1]==maxr[k][1])&&maxp[i][3]&&maxq[j][3]&&maxr[k][3])
					{
						if(maxp[i][1]==maxq[i][1]&&maxp[i][1]==maxr[i][1])
						{
						    int cnt=max(max(maxp[i][2],maxq[j][2]),maxr[k][2]);
						    ans+=cnt;
						    if(cnt==maxp[i][2])
						    {
						    	maxp[i][3]=0;
						    	maxq[j][3]=0;
						    	maxr[k][3]=0;
							}
							else if(cnt==maxq[j][2])
							{
								maxp[i][3]=0;
						    	maxq[j][3]=0;
						    	maxr[k][3]=0;
							}
							else 
							{
								maxp[i][3]=0;
						    	maxq[j][3]=0;
						    	maxr[k][3]=0;
							}
						}
						else if(maxp[i][1]==maxq[j][1])
						{
							int cnt=max(maxp[i][2],maxq[j][2]);
							ans+=cnt;
							if(cnt==maxp[i][2])
							{
								maxp[i][3]=0;
						    	maxq[j][3]=0;
						    	maxr[k][3]=0;
							}
							else 
							{
								maxp[i][3]=0;
						    	maxq[j][3]=0;
						    	maxr[k][3]=0;
							}
						}
						else if(maxp[i][1]==maxr[k][1])
						{
							int cnt=max(maxp[i][2],maxr[k][2]);
							ans+=cnt;
							if(cnt==maxp[i][2])
							{
								maxp[i][3]=0;
						    	maxq[j][3]=0;
						    	maxr[k][3]=0;
							}
							else 
							{
								maxp[i][3]=0;
						    	maxq[j][3]=0;
						    	maxr[k][3]=0;
							}
						}
						else if(maxr[k][1]==maxq[j][1])
						{
							int cnt=max(maxr[k][2],maxq[j][2]);
							ans+=cnt;
							if(cnt==maxq[i][2])
							{
								maxp[i][3]=0;
						    	maxq[j][3]=0;
						    	maxr[k][3]=0;
							}
							else 
							{
								maxp[i][3]=0;
						    	maxq[j][3]=0;
						    	maxr[k][3]=0;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n/2;i++)
		{
			int cnt=max(max(maxp[i][2],maxq[i][2]),maxr[i][2]);
			ans+=cnt;
			if(cnt==maxp[i][2])
			{
				maxp[i][3]=0;
			 	maxq[i][3]=0;
				maxr[i][3]=0;
			}
			else if(cnt==maxq[i][2])
			{
				maxp[i][3]=0;
				maxq[i][3]=0;
				maxr[i][3]=0;
			}
			else 
			{
				maxp[i][3]=0;
				maxq[i][3]=0;
				maxr[i][3]=0;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
