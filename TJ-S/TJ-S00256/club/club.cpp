#include<bits/stdc++.h>
using namespace std;
int t,n,k,j,q;
long long ans;
struct stu
{
	int f,s,t;
};
stu a[100005];
bool cmp1(stu a,stu b)
{
	return a.f-max(a.s,a.t)>b.f-max(b.s,b.t);
}
bool cmp2(stu a,stu b)
{
	return a.s-max(a.t,a.f)>b.s-max(b.t,b.f);
}
bool cmp3(stu a,stu b)
{
	return a.t-max(a.s,a.f)>b.t-max(b.s,b.f);
}
int ls1,ls2,ls3;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].f>>a[i].s>>a[i].t;
		}
		sort(a+1,a+1+n,cmp1);
		for(k=1;k<=n/2;k++)
		{
			if(a[k].f-max(a[k].s,a[k].t)<0)break;
			ans+=a[k].f;
		}
		
		ls1=n/2-k+1;
		if(ls1==0)
		{
			for(int i=k;i<=n;i++)ans+=max(a[i].s,a[i].t);
			cout<<ans<<'\n';continue;
		}
		else
		{
			sort(a+k,a+1+n,cmp2);
			for(j=k;j<=n/2+k-1;j++)
			{
				if(a[j].s-max(a[j].f,a[j].t)<0)break;
				ans+=a[j].s;
			}
			ls2=n/2-j+k;
			if(ls2==0)
			{
				for(int i=j;i<=n;i++)ans+=max(a[i].f,a[i].t);
				cout<<ans<<'\n';continue;
			}
			else
			{
				sort(a+j,a+1+n,cmp3);
				for(q=j;q<=n/2+j-1&&q<=n;q++)
				{
					if(a[q].t-max(a[q].f,a[q].s)<0)break;
					ans+=a[q].t;
				}
				if(q==n+1)
				{
					cout<<ans<<'\n';continue;
				}
				ls3=n/2-q+j;
				if(ls3==0)
				{
					for(int i=q;i<=n;i++)ans+=max(a[i].f,a[i].s);
					cout<<ans<<'\n';continue;
				}
				
			}
		}
	}
	return 0;
}
