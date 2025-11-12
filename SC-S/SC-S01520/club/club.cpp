#include<bits/stdc++.h>
using namespace std;
struct people{
	int a;int b;int c;
};
bool cmp(people x,people y)
{
	if(x.a==y.a)
	{
		if(x.b==y.b)return x.c<=y.c;
		else return x.b<y.b;
	}
	return x.a<y.a;
}
int solve()
{
	int n,d=0,e=0,f=0;
	cin>>n;
	int qq=n+3;
	long long sum[qq]={0};
	people man[n];
	for(int i=1;i<=n;i++)
	{
		cin>>man[i].a>>man[i].b>>man[i].c;
	}
	sort(man,man+n,cmp);
	for(int i=1;i<=n;i++)
	{
		sum[i]=max(man[i].a,max(man[i].b,man[i].c))+sum[i-1];
		if(max(man[i].a,max(man[i].b,man[i].c))==man[i].a)d++;
		else if(max(man[i].a,max(man[i].b,man[i].c))==man[i].b)e++;
		else if(max(man[i].a,max(man[i].b,man[i].c))==man[i].c)f++;
		if(d>n/2)
		{
			d--;
			sum[i]=max(sum[i-1]+max(man[i].b,man[i].c),sum[i-2]+man[i].a+max(man[i-1].b,man[i-1].c));
		}
		if(e>n/2)
		{
			e--;
			sum[i]=max(sum[i-1]+max(man[i].a,man[i].c),sum[i-2]+man[i].b+max(man[i-1].a,man[i-1].c));
		}
		if(f>n/2)
		{
			f--;
			sum[i]=max(sum[i-1]+max(man[i].a,man[i].b),sum[i-2]+man[i].c+max(man[i-1].a,man[i-1].b));	
		}
	}
	cout<<sum[n]<<endl;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int nn;
	cin>>nn;
	while(nn--)
	{
		solve();
	}
	return 0;
}