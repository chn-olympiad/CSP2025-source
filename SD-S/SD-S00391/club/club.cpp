#include <bits/stdc++.h>
using namespace std;
int t,n,numa,numb,numc;
int a[100010],b[100010],c[100010];
long long ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0;
		numa=0;
		numb=0;
		numc=0;
		priority_queue<int,vector<int>,greater<int> > qa;
		priority_queue<int,vector<int>,greater<int> > qb;
		priority_queue<int,vector<int>,greater<int> > qc;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
		}
		for(int i=1;i<=n;i++)
		{
			int mmax=max(a[i],max(b[i],c[i]));
			if(mmax==a[i])
			{
				if(numa<(n/2))
				{
					qa.push(mmax-max(b[i],c[i]));
					numa++;
					ans+=a[i];
				}
				else
				{
					if((mmax-max(b[i],c[i]))<qa.top())
					{
						ans+=max(b[i],c[i]);
					}
					else
					{
						ans-=qa.top();
						qa.pop();
						ans+=a[i];
						qa.push(mmax-max(b[i],c[i]));
					}
				}
				continue;
			}
			
			if(mmax==b[i])
			{
				if(numb<(n/2))
				{
					qb.push(mmax-max(a[i],c[i]));
					numb++;
					ans+=b[i];
				}
				else
				{
					if((mmax-max(a[i],c[i]))<qb.top())
					{
						ans+=max(a[i],c[i]);
					}
					else
					{
						ans-=qb.top();
						qb.pop();
						ans+=b[i];
						qb.push(mmax-max(a[i],c[i]));
					}
				}
				continue;
			}
			
			if(mmax==c[i])
			{
				if(numc<(n/2))
				{
					qc.push(mmax-max(b[i],a[i]));
					numc++;
					ans+=c[i];
				}
				else
				{
					if((mmax-max(b[i],a[i]))<qc.top())
					{
						ans+=max(b[i],a[i]);
					}
					else
					{
						ans-=qc.top();
						qc.pop();
						ans+=c[i];
						qc.push(mmax-max(b[i],a[i]));
					}
				}
				continue;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

