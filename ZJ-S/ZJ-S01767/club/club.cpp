#include<bits/stdc++.h>
using namespace std;
struct point
{
	int p1,p2,p3;
}s[100005];

int c1=0,c2=0,c3=0;
int s1=0,s2=0,s3=0;
bool cmp(point a,point b)
{
	return a.p1>b.p1;
	if(a.p1==b.p1)	return a.p2==b.p2? a.p2>b.p2:a.p3>b.p3;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>s[i].p1>>s[i].p2>>s[i].p3;
		}
		sort(s+1,s+n+1,cmp);
		bool f=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i].p2!=0 or s[i].p3!=0) f=1;
		}
		if(!f)
		{
			for(int i=1;i<=n/2;i++)
			{
				s1+=s[i].p1;
			}
			cout<<s1;
		}
		if(f)
		{
			for(int i=1;i<=n;i++)
			{
				if(s[i].p1 == max(max(s[i].p1,s[i].p2),s[i].p3) )
				{
					if(c1>=n/2) s[i].p1=-1;
					else c1++,s1+=s[i].p1;
				}
				else if(s[i].p2 == max(max(s[i].p1,s[i].p2),s[i].p3) )
				{
					if(c2>=n/2) s[i].p2=-1;
					else c2++,s2+=s[i].p2;
				}
				else if(s[i].p3 == max(max(s[i].p1,s[i].p2),s[i].p3) )
				{
					c3++,s3+=s[i].p3;
				}
			}
			cout<<s1+s2+s3<<'\n';
		}
		s1=s2=s3=c1=c2=c3=0;
	}
	return 0;
}
