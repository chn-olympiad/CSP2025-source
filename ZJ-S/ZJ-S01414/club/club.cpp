#include<bits/stdc++.h>
using namespace std;
int t,n,max3,max2,mx,s;
struct dd
{
	int s1,s2,s3;
}a[100001];
void dfs(int c,int zzz,int zzz1,int zzz2,int zzz3)
{
	if(zzz1>(n/2)||zzz2>(n/2)||zzz3>(n/2))
	  return;
	  
	if(c>n)
	{
		mx=max(mx,zzz);
		return;
	}
	dfs(c+1,zzz+a[c].s1,zzz1+1,zzz2,zzz3);
	dfs(c+1,zzz+a[c].s2,zzz1,zzz2+1,zzz3);
	dfs(c+1,zzz+a[c].s3,zzz1,zzz2,zzz3+1);
}
bool cmp(dd x,dd y)
{
	return x.s1>y.s1;
}
bool cmp2(dd x,dd y)
{
	return (x.s1-x.s2)>(y.s1-y.s2);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int ii=1;ii<=t;++ii)
	{
		mx=0;
		s=0;
		max2=0;
		max3=0;
		cin>>n;
		for(int i=1;i<=n;++i)
		{
			cin>>a[i].s1>>a[i].s2>>a[i].s3;
			max2=max(max2,a[i].s2);
			max3=max(max3,a[i].s3);
		}
		if(n<=10)
		{
			dfs(1,0,0,0,0);//yi
			cout<<mx;
		}else
		if(max3==0)
		{
			if(max2==0)
			{
				sort(a+1,a+1+n,cmp);
				for(int i=1;i<=n/2;++i)
				  s+=a[i].s1;
			}else
			{
				sort(a+1,a+1+n,cmp2);
				for(int i=1;i<=n/2;++i)
				  s+=a[i].s1;
				for(int i=n/2+1;i<=n;++i)
				  s+=a[i].s2;
			}
			cout<<s<<'\n';
		}
	}
	return 0;
}