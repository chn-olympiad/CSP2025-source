#include<bits/stdc++.h>
using namespace std;
struct club
{
	int x,y,z,xn,yn,zn,q1,q2,q3;
}a[100010];
int n,sum=0,xk,zk,yk;
bool cmp1(club b,club c)
{
	return b.x>c.x;
}
bool cmp2(club b,club c)
{
	return b.y>c.y;
}
bool cmp3(club b,club c)
{
	return b.z>c.z;
}
void zc()
{
	for(int i=1;i<=n;i++)
	{
		if(a[i].zn<a[i].xn&&a[i].xn<a[i].yn&&zk<n/2)
		{
			sum+=a[i].z;
			zk++;
		}
		else if(a[i].zn>a[i].xn&&a[i].xn<a[i].yn&&xk<n/2)
		{
			sum+=a[i].x;
			xk++;
		}
		else if(a[i].yn<a[i].xn&&a[i].yn<a[i].zn&&yk<n/2)
		{
			sum+=a[i].y;
			yk++;
		}
		else if(a[i].zn==a[i].xn&&a[i].zn<a[i].yn)
		{
			if(a[i].z>a[i].x&&zk<n/2)
			{
				sum+=a[i].z;
				zk++;
			}
			else if(a[i].z==a[i].x)
			{
				if(zk<=xk)
				{
					sum+=a[i].z;
					zk++;
				}
				else
				{
					sum+=a[i].x;
					xk++;
				}
			}
			else
			{
				sum+=a[i].x;
				xk++;
			}
		}
		else if(a[i].zn==a[i].xn&&a[i].zn==a[i].yn)
		{
			if(a[i].z>a[i].x&&a[i].x>a[i].y&&zk<n/2)
			{
				sum+=a[i].z;
				zk++;
			}
			else if(a[i].z<a[i].x&&a[i].x>a[i].y&&xk<n/2)
			{
				sum+=a[i].x;
				xk++;
			}
			else if(a[i].z<a[i].x&&a[i].x<a[i].y&&yk<n/2)
			{
				sum+=a[i].y;
				yk++;
			}
			else if(a[i].z==a[i].x&&a[i].x>a[i].y)
			{
				if(zk<xk&&zk<n/2)
				{
					sum+=a[i].z;
					zk++;
				}
				else
				{
					sum+=a[i].x;
					xk++;
				}
			}
			else if(a[i].z==a[i].x&&a[i].x==a[i].y)
			{
				if(zk<=xk&&xk<yk&&zk<n/2)
				{
					sum+=a[i].z;
					zk++;
				}
				else if(zk>xk&&xk<=yk&&xk<n/2)
				{
					sum+=a[i].x;
					xk++;
				}
				else
				{
					sum+=a[i].y;
					yk++;
				}
			}
			else if(a[i].z==a[i].y&&a[i].z>a[i].x)
			{
				if(zk<=yk&&zk<n/2)
				{
					sum+=a[i].z;
					zk++;
				}
				else
				{
					sum+=a[i].y;
					yk++;
				}
			}
			else
			{
				if(xk<=yk&&xk<n/2)
				{
					sum+=a[i].x;
					xk++;
				}
				else
				{
					sum+=a[i].y;
					yk++;
				}
			}
		}
		else if(a[i].zn>a[i].xn&&a[i].xn==a[i].yn)
		{
			if(a[i].y>a[i].x&&yk<n/2)
			{
				sum+=a[i].y;
				yk++;
			}
			else if(a[i].y==a[i].x)
			{
				if(yk<=xk&&yk<n/2)
				{
					sum+=a[i].y;
					yk++;
				}
				else
				{
					sum+=a[i].x;
					xk++;
				}
			}
			else
			{
				sum+=a[i].x;
				xk++;
			}
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		n=0,sum=0,xk=0,yk=0,zk=0;
		bool temp1=0,temp2=0,temp3=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x!=0)
			{
				temp1=1;
			}
			if(a[i].y!=0)
			{
				temp2=1;
			}
			if(a[i].z!=0)
			{
				temp3=1;
			}
			if(a[i].x==0&&a[i].y==0)
			{
				a[i].q3=-1;
			}
			if(a[i].x==0&&a[i].z==0)
			{
				a[i].q2=-1;
			}
			if(a[i].z==0&&a[i].y==0)
			{
				a[i].q1=-1;
			}
		}
		if(temp1==0&&temp2==0)
		{
			sort(a+1,a+n+1,cmp3);
			for(int i=1;i<=n/2;i++)
			{
				sum+=a[i].z;
			}
			cout<<sum<<endl;
			continue;
		}
		if(temp2==0&&temp3==0)
		{
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n/2;i++)
			{
				sum+=a[i].x;
			}
			cout<<sum<<endl;
			continue;
		}
		if(temp1==0&&temp3==0)
		{
			sort(a+1,a+n+1,cmp2);
			for(int i=1;i<=n/2;i++)
			{
				sum+=a[i].y;
			}
			cout<<sum<<endl;
			continue;
		}
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=n;i++)
		{
			a[i].xn=i;
			if(a[i].q1=-1)
			{
				a[i].xn=i-2;
			}
		}
		sort(a+1,a+n+1,cmp2);
		for(int i=1;i<=n;i++)
		{
			a[i].yn=i;
			if(a[i].q2=-1)
			{
				a[i].yn=i-2;
			}
		}
		sort(a+1,a+n+1,cmp3);
		for(int i=1;i<=n;i++)
		{
			a[i].zn=i;
			if(a[i].q3=-1)
			{
				a[i].zn=i-2;
			}
		}
		sort(a+1,a+n+1,cmp1);
		zc();
		cout<<sum<<endl;
	}
	return 0;
 } 
