#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
struct node{
	int x,y,z,maxx;
}a[N];
bool cmp(node a,node b)
{
	return a.maxx>b.maxx;
}
int t,n;
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].maxx=max(a[i].x,max(a[i].y,a[i].z));
		}
		int sum=0,maxn=0,xx=0,yy=0,zz=0;
		bool fl1=0,fl2=0,fl3=0;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			//x
			if(a[i].x>a[i].y&&a[i].x>a[i].z&&fl1==0)
			{
				xx++;sum+=a[i].x;
				if(xx==n/2)fl1=1;
				continue;
			}
			if(a[i].x>a[i].y&&a[i].x>a[i].z&&fl1==1)
			{
				if(a[i].y>a[i].z)yy++,sum+=a[i].y;
				else zz++,sum+=a[i].z;
				continue;
			}
			//y
			if(a[i].y>a[i].x&&a[i].y>a[i].x&&fl2==0)
			{
				yy++;sum+=a[i].y;
				if(yy==n/2)fl2=1;
				continue;
			}
			if(a[i].y>a[i].x&&a[i].y>a[i].x&&fl2==1)
			{
				if(a[i].x>a[i].z)xx++,sum+=a[i].x;
				else zz++,sum+=a[i].z;
				continue;
			}
			//z
			if(a[i].z>a[i].x&&a[i].z>a[i].y&&fl3==0)
			{
				zz++;sum+=a[i].z;
				if(zz==n/2)fl3=1;
				continue;
			}
			if(a[i].z>a[i].x&&a[i].z>a[i].y&&fl3==1)
			{
				if(a[i].y>a[i].x)yy++,sum+=a[i].y;
				else xx++,sum+=a[i].x;
				continue;
			}
		}
		maxn=sum;sum=0;xx=0,yy=0,zz=0;
		fl1=0,fl2=0,fl3=0;
		//cout<<maxn<<" ";
		for(int i=n;i>=1;i--)
		{
			//x
			if(a[i].x>a[i].y&&a[i].x>a[i].z&&fl1==0)
			{
				xx++;sum+=a[i].x;
				if(xx==n/2)fl1=1;
				continue;
			}
			if(a[i].x>a[i].y&&a[i].x>a[i].z&&fl1==1)
			{
				if(a[i].y>a[i].z)yy++,sum+=a[i].y;
				else zz++,sum+=a[i].z;
				continue;
			}
			//y
			if(a[i].y>a[i].x&&a[i].y>a[i].x&&fl2==0)
			{
				yy++;sum+=a[i].y;
				if(yy==n/2)fl2=1;
				continue;
			}
			if(a[i].y>a[i].x&&a[i].y>a[i].x&&fl2==1)
			{
				if(a[i].x>a[i].z)xx++,sum+=a[i].x;
				else zz++,sum+=a[i].z;
				continue;
			}
			//z
			if(a[i].z>a[i].x&&a[i].z>a[i].y&&fl3==0)
			{
				zz++;sum+=a[i].z;
				if(zz==n/2)fl3=1;
				continue;
			}
			if(a[i].z>a[i].x&&a[i].z>a[i].y&&fl3==1)
			{
				if(a[i].y>a[i].x)yy++,sum+=a[i].y;
				else xx++,sum+=a[i].x;
				continue;
			}
		}
		maxn=max(sum,maxn);
		cout<<maxn<<"\n";
	}
	return 0;
}
/*
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
4 0 0
*/
