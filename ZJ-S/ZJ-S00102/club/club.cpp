#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int p1,p2,p3;
struct node
{
	int mc1;
	int mc2;
	int m1;
	int m2;
	int m3;
	int mh1;
	int mh2;
	int mh3;
}p[100005];
bool cmp(node a,node b)
{
	if(a.mc1==b.mc1)
	{
		return a.mc2>b.mc2;
	}
	return a.mc1>b.mc1;
}
int s[5];
long long sum;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		sum=0;
		memset(s,0,sizeof(s));
		int n;
		cin>>n;
		int maxp=n/2;
		for(int j=1;j<=n;j++)
		{
			cin>>p1>>p2>>p3;
			bool a=false,b=false,c=false;
			p[j].m1=max(p1,max(p2,p3));
			p[j].m3=min(p1,min(p2,p3));
			p[j].mc1=p1+p2+p3;
			p[j].mc1-=(p[j].m1+p[j].m3);
			p[j].m2=p[j].mc1;
			p[j].mc1=p[j].m1-p[j].mc1;
			p[j].mc2=p[j].m2-p[j].m3;
			if(p[j].m1==p1&&!a)
			{
				p[j].mh1=1;
				a=true;
			}	
			else if(p[j].m1==p2&&!b)
			{
				p[j].mh1=2;
				b=true;
			}
			else
			{
				p[j].mh1=3;
				c=true;
			}
			if(p[j].m2==p1&&!a)
			{
				p[j].mh2=1;
				a=true;
			}	
			else if(p[j].m2==p2&&!b)
			{
				p[j].mh2=2;
				b=true;
			}
			else
			{
				p[j].mh2=3;
				c=true;
			}
			if(p[j].m3==p1&&!a)
			{
				p[j].mh3=1;
				a=true;
			}	
			else if(p[j].m3==p2&&!b)
			{
				p[j].mh3=2;
				b=true;
			}
			else
			{
				p[j].mh3=3;
				c=true;
			}
		}
		sort(p+1,p+1+n,cmp);
		for(int j=1;j<=n;j++)
		{
			if(s[p[j].mh1]+1<=maxp)
			{
				sum+=p[j].m1;
				s[p[j].mh1]++;
			}
			else if(s[p[j].mh2]+1<=maxp)
			{
				sum+=p[j].m2;
				s[p[j].mh2]++;
			}
			else
			{
				sum+=p[j].m3;
				s[p[j].mh3]++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}