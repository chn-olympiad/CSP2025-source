#include<bits/stdc++.h>
using namespace std;
long long int s;
int v[100005],a1,b1,c1;
struct node
{
	int a,b;
}q[100005];
bool cmp(node a,node b)
{
	return a.a<b.a;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		s=0;
		a1=0,b1=0,c1=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			if(a>b&&a>c)
			{
				a1++;
				s+=a;
				v[i]=1;
				q[i].a=min(a-b,a-c);
				q[i].b=i;
			}
			else
			if(b>c)
			{
				b1++;
				s+=b;
				v[i]=2;
				q[i].a=min(b-a,b-c);
				q[i].b=i;
			}
			else
			{
				c1++;
				s+=c;
				v[i]=3;
				q[i].a=min(c-a,c-b);
				q[i].b=i;
			}
		}
		sort(q+1,q+1+n,cmp);
		int t=0;
		if(a1>(n/2))
		while(a1>n/2)
		{
			t++;
			if(v[q[t].b]==1)
			{
				s-=q[t].a;
				a1--;
			}
			else
			continue;
		}
		if(b1>(n/2))
		while(b1>n/2)
		{
			t++;
			if(v[q[t].b]==2)
			{
				s-=q[t].a;
				b1--;
			}
			else
			continue;
		}
		if(c1>(n/2))
		while(c1>n/2)
		{
			t++;
			if(v[q[t].b]==3)
			{
				s-=q[t].a;
				c1--;
			}
			else
			continue;
		}
		cout<<s<<endl;
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
