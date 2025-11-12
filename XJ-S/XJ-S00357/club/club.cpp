#include<bits/stdc++.h>
using namespace std;

const int N=1e5;
struct str{
	int first,second,thired;
	bool zong=true;
}a[N+5];
int st,nd,ed;
int n,t,ans;
bool solve(int x)
{
	return n>=x*2;
}
bool cmp1(str a,str b)
{
	return a.first>b.first;
}
bool cmp2(str a,str b)
{
	return a.second>b.second;
}
bool cmp3(str a,str b)
{
	return a.thired>b.thired;
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
			cin>>a[i].first>>a[i].second>>a[i].thired;
		}
		for(int i=1;i<=n;i++)
		{
			sort(a+1,a+1+n,cmp1);
			if(a[i].first>=a[i].second>=a[i].thired && a[i].zong)
			{
				if(!solve(st))
				{
					nd++;
					ans+=a[i].second;
					a[i].zong=false;
				}
				else if(!solve(nd))
				{
					ed++;
					ans+=a[i].thired;
					a[i].zong=false;
				}
				else
				{
					st++;
					ans+=a[i].first;
					a[i].zong=false;
				}
			}
			if(a[i].first>=a[i].thired>=a[i].second && a[i].zong)
			{
				if(!solve(st))
				{
					ed++;
					ans+=a[i].thired;
					a[i].zong=false;
				}
				else if(!solve(ed))
				{
					nd++;
					ans+=a[i].second;
					a[i].zong=false;
				}
				else
				{
					st++;
					ans+=a[i].first;
					a[i].zong=false;
				}
			}
			sort(a+1,a+1+n,cmp2);
		if(a[i].second>=a[i].first>=a[i].thired && a[i].zong)
		{
			if(!solve(nd))
			{
				st++;
				ans+=a[i].first;
				a[i].zong=false;
			}
			else if(!solve(st))
				{
					ed++;
					ans+=a[i].thired;
					a[i].zong=false;
				}
			else
			{
				nd++;
				ans+=a[i].second;
				a[i].zong=false;
			}
		}
		if(a[i].second>=a[i].thired>=a[i].first && a[i].zong)
		{
			if(!solve(nd))
			{
				ed++;
				ans+=a[i].thired;
				a[i].zong=false;
			}
			else if(!solve(ed))
				{
					st++;
					ans+=a[i].first;
					a[i].zong=false;
				}
			else
			{
				nd++;
				ans+=a[i].second;
				a[i].zong=false;
			}
		}
		sort(a+1,a+1+n,cmp3);
		if(a[i].thired>=a[i].first>=a[i].second && a[i].zong)
		{
			if(!solve(ed))
			{
				st++;
				ans+=a[i].first;
				a[i].zong=false;
			}
			else if(!solve(st))
				{
					nd++;
					ans+=a[i].second;
					a[i].zong=false;
				}
			else
			{
				ed++;
				ans+=a[i].thired;
				a[i].zong=false;
			}
		}
		if(a[i].thired>=a[i].second>=a[i].first && a[i].zong)
		{
			if(!solve(ed))
			{
				nd++;
				ans+=a[i].second;
				a[i].zong=false;
			}
			else if(!solve(nd))
				{
					st++;
					ans+=a[i].first;
					a[i].zong=false;
				}
			else
			{
				ed++;
				ans+=a[i].thired;
				a[i].zong=false;
			}
		}
	}
		cout<<ans<<endl;
		for(int i=1;i<=n;i++)
		{
			a[i].first=a[i].second=a[i].thired=0;
			a[i].zong=true;
		}
		st=nd=ed=0;
		ans=0;
		n=0;
		
		
	}
	return 0;
}

