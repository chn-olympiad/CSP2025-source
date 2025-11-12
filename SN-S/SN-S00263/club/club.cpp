#include<bits/stdc++.h>
#define ll long long 
using namespace std;
struct node
{
	ll a,b,c;
	ll ab,bc,ac;
	ll id;
	ll mi;
};
ll T;
ll n;
node stu[100100];
vector<node> a,b,c;
bool cmp(node &a,node &b)
{
	return a.mi<b.mi;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr); 
	cin>>T;
	while(T--)
	{
		ll ans=0;
		a.clear();
		b.clear();
		c.clear();
		cin>>n;
		for(ll i=1;i<=n;i++)
		{
			cin>>stu[i].a>>stu[i].b>>stu[i].c;
			stu[i].ab=abs(stu[i].a-stu[i].b);
			stu[i].ac=abs(stu[i].a-stu[i].c);
			stu[i].bc=abs(stu[i].b-stu[i].c);
			stu[i].id=i;
			if(stu[i].a>=stu[i].b&&stu[i].a>=stu[i].c)
			{
				
				stu[i].mi=min(stu[i].ab,stu[i].ac);
				a.push_back(stu[i]);
			}
			else if(stu[i].b>=stu[i].a&&stu[i].b>=stu[i].c)
			{
				stu[i].mi=min(stu[i].ab,stu[i].bc);
				b.push_back(stu[i]);
			}
			else if(stu[i].c>=stu[i].a&&stu[i].c>=stu[i].b)
			{
				stu[i].mi=min(stu[i].ac,stu[i].bc);
				c.push_back(stu[i]);
			}
		}
//		printf("lena=%d lenb=%d lenc=%d\n",a.size(),b.size(),c.size());
		for(auto x:a) ans+=x.a;
		for(auto x:b) ans+=x.b;
		for(auto x:c) ans+=x.c;
		if(a.size()>n/2)
		{
			sort(a.begin(),a.end(),cmp);
			for(ll i=0;i<a.size()-n/2;i++)
				ans-=a[i].mi;
		}
		else if(b.size()>n/2)
		{
			sort(b.begin(),b.end(),cmp);
			for(ll i=0;i<b.size()-n/2;i++)
				ans-=b[i].mi;
		}
		else if(c.size()>n/2)
		{
			sort(c.begin(),c.end(),cmp);
			for(ll i=0;i<c.size()-n/2;i++)
				ans-=c[i].mi;
		}
		cout<<ans<<'\n';
	}
	
}
