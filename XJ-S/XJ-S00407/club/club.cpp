#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		int a[100010][5]={0};
		a[100005][1]=99999;
		a[100005][2]=99999;
		a[100005][3]=99999;
		int x=0,y=0,z=0;
		int xi=100005,yi=100005,zi=100005;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a[i][1];
			cin>>a[i][2];
			cin>>a[i][3];
		}
		if(n==2)
		{
			int ma=-1;
			ma=max(ma,a[0][1]+a[1][2]);
			ma=max(ma,a[0][1]+a[1][3]);
			ma=max(ma,a[0][2]+a[1][1]);
			ma=max(ma,a[0][2]+a[1][3]);
			ma=max(ma,a[0][3]+a[1][1]);
			ma=max(ma,a[0][4]+a[1][2]);
			cout<<ma<<endl;
			continue;
		}
		for(int i=0;i<n;i++)
		{
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
			{
				a[i][4]=1;
				x++;
				if(a[xi][1]>a[i][1])
				{
					xi=i;
				}
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
			{
				a[i][4]=2;
				y++;
				if(a[yi][2]>a[i][2])
				{
					yi=i;
				}
			}
			else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2])
			{
				a[i][4]=3;
				z++;
				if(a[zi][3]>a[i][3])
				{
					zi=i;
				}
			}
		}
		while(x>n/2)
		{
			if(a[xi][2]<a[xi][3])
			{
				a[xi][4]=3;
			}
			else
			{
				a[xi][4]=2;
			}
			x--;
			xi=100005;
			for(int i=0;i<n;i++)
			{
				if(a[i][4]==1&&a[i][1]<a[xi][1])
				{
					xi=i;
				}
			}
		}
		while(y>n/2)
		{
			if(a[yi][1]<a[yi][3])
			{
				a[yi][4]=3;
			}
			else
			{
				a[yi][4]=1;
			}
			y--;
			yi=100005;
			for(int i=0;i<n;i++)
			{
				if(a[i][4]==2&&a[i][2]<a[yi][2])
				{
					yi=i;
				}
			}
		}
		while(z>n/2)
		{
			if(a[zi][1]<a[zi][2])
			{
				a[zi][4]=2;
			}
			else
			{
				a[zi][4]=1;
			}
			z--;
			zi=100005;
			for(int i=0;i<n;i++)
			{
				if(a[i][4]==3&&a[i][3]<a[zi][3])
				{
					zi=i;
				}
			}
		}
		int ma=0;
		for(int i=0;i<n;i++)
		{
			ma+=a[i][a[i][4]];
		}
		cout<<ma<<endl;
	}
	
	
	return 0;
}
