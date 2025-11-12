#include<bits/stdc++.h>
//#define int long long
//#define pqg priority_queue<int ,vector<int>,greater>
//#define pql priority_queue<int ,vector<int> >
using namespace std;
int t,n;
struct cg
{
	int x1,x2,x3,z;
}a[1000005];
bool cmp(cg x,cg y)
{
	return x.z<y.z;
}
signed main()
{
	cin.tie();
	cout.tie();
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int ans=0,s1=0,s2=0,s3=0;
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j].x1>>a[j].x2>>a[j].x3;
			if(a[j].x1>=a[j].x2&&a[j].x1>=a[j].x3)
			{
				ans+=a[j].x1,s1++;
				continue;
			}
			if(a[j].x2>=a[j].x1&&a[j].x2>=a[j].x3)
			{
				ans+=a[j].x2,s2++;
				continue;
			}
			if(a[j].x3>=a[j].x1&&a[j].x3>=a[j].x2)
			{
				ans+=a[j].x3,s3++;
				continue;
			}
		}
		if(s1>n/2)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[j].x1>=a[j].x2&&a[j].x1>=a[j].x3)a[j].z=min(a[j].x1-a[j].x2,a[j].x1-a[j].x3);
				else a[j].z=1e9;
			}
			sort(a+1,a+1+n,cmp);
			int l=1;
			while(s1>n/2)
			{
				ans=ans-a[l].z;
				++l,--s1;
			}
		}
		if(s2>n/2)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[j].x2>=a[j].x1&&a[j].x2>=a[j].x3)a[j].z=min(a[j].x2-a[j].x1,a[j].x2-a[j].x3);
				else a[j].z=1e9;
			}
			sort(a+1,a+1+n,cmp);
			int l=1;
			while(s2>n/2)
			{
				ans=ans-a[l].z;
				++l,--s2;
			}
		}
		if(s3>n/2)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[j].x3>=a[j].x1&&a[j].x3>=a[j].x2)a[j].z=min(a[j].x3-a[j].x1,a[j].x3-a[j].x2);
				else a[j].z=1e9;
			}
			sort(a+1,a+1+n,cmp);
			int l=1;
			while(s3>n/2)
			{
				ans=ans-a[l].z;
				++l,--s3;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
