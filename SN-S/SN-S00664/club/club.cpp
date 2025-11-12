#include<bits/stdc++.h>
using namespace std;
int n,t,ans=0,g=0;
struct node{int a,b,c;}a[100100];
bool cmp(node a,node b)
{
	if(a.a==b.a)
	{
		if(a.b==b.b)
		{
			return a.c>b.c;
		}
		return a.b>b.b;
	}
	return a.a>b.a;
}
int main()
{
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a>>a[i].b>>a[i].c;
		}
		ans=0;
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++)
		{
			int ret=0;
			if(ret<n/2&&g==0) ans+=a[i].a,ret++,g=1;
			if(ret<n/2&&g==1) ans+=a[i].b,ret++,g=2;
			if(ret<n/2&&g==2) ans+=a[i].c,ret++;
		}
		cout<<ans<<endl;
	}

	return 0;
}  
