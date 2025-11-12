#include <bits/stdc++.h>
using namespace std;
int t,n,x1[100005],x2[100005],x3[100005],ans[100005],nu;
long long s;
bool p1[100005],p2[100005],p3[100005];
struct yy
{
	int x[5];
}a[100005];
struct cc
{
	int ans1,from;
	long long anss;
}c[100005];
bool cmp1(int x1,int x2)
{
	return a[x1].x[1]>=a[x2].x[1];
}
bool cmp2(int x1,int x2)
{
	return a[x1].x[2]>=a[x2].x[2];
}
bool cmp3(int x1,int x2)
{
	return a[x1].x[3]>=a[x2].x[3];
}
bool cmpc(cc a,cc b)
{
	return a.anss>b.anss;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while (t--)
	{
		s=0;
		nu=0;
		memset(p1,0,sizeof p1);
		memset(p2,0,sizeof p2);
		memset(p3,0,sizeof p3);
		cin >> n;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<4;j++)
			{
				cin >> a[i].x[j];
			}
			x1[i]=x2[i]=x3[i]=i;
		}
		sort(x1+1,x1+n+1,cmp1);
		sort(x2+1,x2+n+1,cmp2);
		sort(x3+1,x3+n+1,cmp3);
		for (int i=1;i<=n/2;i++)
		{
			s+=a[x1[i]].x[1];
			p1[x1[i]]=1;
		}
		for (int i=1;i<=n;i++)
		{
			if (p1[x2[i]]) continue;
			ans[++nu]=x2[i];
			p2[x2[i]]=1;
			s+=a[x2[i]].x[2];
			if (nu==n/2) break;
		}
		for (nu;nu>0;nu--)//ур2
		{
			long long anss=0;
			int ans1=0,ans2=0;
			for (int i=1;i<=n;i++)
			{
				if (p2[x2[i]]) continue;
				if (p1[x2[i]])
				{
					long long s2=s+a[x2[i]].x[2]-a[x2[i]].x[1]+a[ans[nu]].x[1]-a[ans[nu]].x[2];
					if (s2>=s and s2>=anss)
					{
						anss=s2;
						ans1=x2[i];
						ans2=ans[nu];
					}
					else break;
				}
			}
			if (anss!=0)
			{
				s=anss;
				p1[ans1]=0;
				p2[ans1]=1;
				p1[ans2]=1;
				p2[ans2]=0;
			}
		}
		nu=0;
		for (int i=1;i<=n;i++)
		{
			if (p1[x3[i]])
			{
				long long s3=s+a[x3[i]].x[3]-a[x3[i]].x[1];
				if (s3>=s)
				{
					c[++nu].ans1=x3[i];
					c[nu].anss=s3-s;
					c[nu].from=1;
				}
			}
			else if (p2[x3[i]])
			{
				long long s3=s+a[x3[i]].x[3]-a[x3[i]].x[2];
				if (s3>=s)
				{
					c[++nu].ans1=x3[i];
					c[nu].anss=s3-s;
					c[nu].from=2;
				}
			}
			else
			{
				c[++nu].ans1=x3[i];
				c[nu].anss=a[x3[i]].x[3];
				c[nu].from=0;
			}
		}
		sort(c+1,c+nu+1,cmpc);
		for (int i=1;i<=min(n/2,nu);i++)
		{
			p3[c[i].ans1]=1;
			s+=c[i].anss;///////////////////////////////
			if (c[i].from==1)
			{
				p1[c[i].ans1]=0;
			}
			else
			{
				p2[c[i].ans1]=0;
			}
		}	
		s=0;
		for (int i=1;i<=n;i++) if (p1[i]) s+=a[i].x[1];
		for (int i=1;i<=n;i++) if (p2[i]) s+=a[i].x[2];
		for (int i=1;i<=n;i++) if (p3[i]) s+=a[i].x[3];
		cout << s << endl;
	}
	return 0;
}