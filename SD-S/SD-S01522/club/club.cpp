#include <bits/stdc++.h>
using namespace std;
int t,n;
struct node{
	int a,b,c,z,q;
}a[100050];
int main() {
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=0;k<t;k++)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a[i].a>>a[i].b>>a[i].c;
		}
		int ans=0,ra=0,rb=0,rc=0;
		for(int i=0;i<n;i++)
		{
			int l=max(a[i].a,max(a[i].b,a[i].c));
			ans+=l;
			if(l==a[i].a) ra++;
			else if(l==a[i].b) rb++;
			else if(l==a[i].c) rc++;
		}
		int l=1e9;
		if(ra>(n/2))
		{
			for(int i=0;i<n;i++)
			{
				int q=0;l=1e9;
				for(int j=0;j<n;j++)
				{
					int ab=abs(a[j].a-a[j].b),ac=abs(a[j].a-a[j].c);
					l=min(l,min(ab,ac));
					if(l==ab) q=1;
					else if(l==ac) q=2;
				}
				if(rb<(n/2)&&q==1)
				{
					ans-=l;
					ra--;rb++;
				}
				else if(rc<(n/2)&&q==2)
				{
					ans-=l;
					ra--;rc++;
				}
				if(ra<=(n/2)) break;
			}
		}
		else if(rb>(n/2))
		{
			for(int i=0;i<n;i++)
			{
				int q=0;l=1e9;
				for(int j=0;j<n;j++)
				{
					int ab=abs(a[j].a-a[j].b),bc=abs(a[j].b-a[j].c);
					l=min(l,min(ab,bc));
					if(l==ab) q=1;
					else if(l==bc) q=2;
				}
				if(ra<(n/2)&&q==1)
				{
					ans-=l;
					rb--;ra++;
				}
				else if(rc<(n/2)&&q==2)
				{
					ans-=l;
					rb--;rc++;
				}
				if(rb<=(n/2)) break;
			}
		}
		else if(rc>(n/2))
		{
			int w=0;
			for(int i=0;i<n;i++)
			{
				int q=0;l=1e9;
				for(int j=0;j<n;j++)
				{
					int bc=abs(a[j].b-a[j].c),ac=abs(a[j].a-a[j].c);
					l=min(l,min(bc,ac));
					if(l==bc)
					{
						w=j;
						q=1;
					}
					else if(l==ac)
					{
						w=j;
						q=2;
					}
				}
				if(rb<(n/2)&&q==1)
				{
					a[i].b=0,a[i].c=1e9;
					ans-=l;
					rc--;rb++;
				}
				else if(ra<(n/2)&&q==2)
				{
					a[i].a=0,a[i].c=1e9;
					ans-=l;
					rc--;ra++;
				}
				if(rc<=(n/2)) break;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

