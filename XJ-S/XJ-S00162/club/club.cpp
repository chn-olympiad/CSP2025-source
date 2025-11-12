#include<bits/stdc++.h>
using namespace std;
long long int t,n,r[5],ans,v[5],m,p;
struct node
{
	int j[5];
	int maxn;
	int zmax;
}q[100005];
bool cmp(node a,node b)
{
	if(a.maxn>b.maxn)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0;
		memset(r,0,sizeof(r));
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>q[i].j[j];
				if(q[i].j[j]>q[i].maxn)
				{
					q[i].maxn=q[i].j[j];
					q[i].zmax=j;
				}
			} 
		}
		sort(q+1,q+1+n,cmp);
		for(int i=1;i<=n;i++)
		{
			m=0;
			p=0;
			memset(v,0,sizeof(v));
			v[q[i].zmax]=1;
			for(int j=1;j<=3;j++)
			{
				if(j!=q[i].zmax)
				{
					v[j]=1;
					for(int k=1;k<=3;k++)
					{
						if(v[k]==0)
						{
							m=k;
							p=j;
							break;
						}
					}
				}
			}
			if(r[q[i].zmax]<n/2)
			{
				r[q[i].zmax]++;
				ans+=q[i].maxn;
			}
			else if(q[i].j[p]<q[i].j[m]&&r[m]<n/2)
			{
				r[m]++;
				ans+=q[i].j[m];
			}
			else
			{
				r[p]++;
				ans+=q[i].j[p];
			}
		}
		cout<<ans;
	}
	return 0;
}
