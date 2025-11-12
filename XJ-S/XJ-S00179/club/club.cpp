#include<bits/stdc++.h>
using namespace std;
long long int t,n,maxn,ans,i,k,l,j,maxnn,x10,y10,x20,y20,a1,a2,b2,b1,z10,z20,c1,c2;
struct node
{
	long long int a,b,c,f=1,k=0,z,m;
}a[100005];
long long int v[1005][1005];
bool cmp(node a,node b)
{
	if(a.a!=b.a)
	return a.a>b.a;
	else
	if(a.b!=b.b)
	return a.b>b.b;
	else
	return a.c>b.c;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n==2)
		{
			cin>>x10>>y10>>z10;
			cin>>x20>>y20>>z20;
			ans=max(max(x10+y20,x20+y10),max(x10+z20,z10+y20)),max(z10+y20,y10+z20);
		}else
		if(n==4)
		{
			cin>>a1>>b1>>c1;
			cin>>a2>>b2>>c1;
			cin>>x10>>y10>>z10;
			cin>>x20>>y20>>z20;
			ans=max(max(max(max(a1+a2+y10+y20,a1+b2+x10+y20),max(a1+b2+y10+x20,b1+a2+x10+y20)),max(b1+b2+x10+x20,b1+a2+y10+x20)),max(max(max(c1+c2+y10+y20,c1+a2+x10+z20),max(c1+a2+z10+x20,a1+c2+z10+x20)),max(c1+a2+x10+y20,c1+c2+x10+x20))),max(max(max(b1+b2+z10+z20,b1+c2+y10+z20),max(b1+c2+z10+y20,c1+c2+y10+y20)),max(c1+b2+x10+z20,c1+b2+z10+y20));
		}
		else
		{
			for(i=1;i<=n;i++)
			cin>>a[i].a>>a[i].b>>a[i].c;
			sort(a+1,a+1+n,cmp);
			for(i=1;i<=n/2;i++)
			{
				ans+=a[i].a;
			}
			for(;i<=n;i++)
			{
				ans+=a[i].b;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
} /*
3
4
4 2 1
3 2 4 
5 3 4
3 5 1
4 
0 1 0
0 1 0
0 2 0
0 2 0
2 
10 9 8
4 0 0*/

