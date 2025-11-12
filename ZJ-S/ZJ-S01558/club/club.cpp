#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x,y,z;
}a[100005];
int b[100005];
bool cmp(node g,node h)
{
	if(g.x==h.x)
		return g.y>h.y;
	return g.x>h.x;
}
int main()
{
 	freopen("club.in","r",stdin);
 	freopen("club.out","w",stdout);
 	std::cin.tie(NULL);
 	std::cout.tie(NULL);
 	int t,n;
 	cin>>t;
 	while(t--)
 	{
 		cin>>n;
 		int p=0,q=0;;
 		for(int i=1;i<=n;i++)
 		{
 			cin>>a[i].x>>a[i].y>>a[i].z;
 			b[i]=a[i].x;
 			if(a[i].y==0&&a[i].z==0)
 			{
 				p++;
			 }
			 if(a[i].z==0)
			 	q++;
		 }
		long long ans=0;
		sort(b+1,b+1+n);
		if(p==n)
		{
			for(int i=n;i>n/2;i--)
				ans+=b[i];
		}
		else if(q==0)
		{
			sort(a+1,a+1+n,cmp);
			int o=n/2,l=n/2;
			for(int i=1;i<=n;i--)
			{
				if(a[i].x>a[i].y&&o>0)
					ans+=a[i].x,o--;
				else if(a[i].x<a[i].y&&l>0)
					ans+=a[i].y,l--;
				else if(o==0&&a[i].x<a[i].y)
					ans+=a[i].y,l--;
				else
					ans+=a[i].x,o--;	
			}
		}
		else if(n==2)
		{
			ans+=max(a[1].x,max(a[1].y,a[1].z))+max(a[2].x,max(a[2].y,a[2].z));
		}
		cout<<ans<<endl;
	 }
 	return 0;
}
