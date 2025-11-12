#include<bits/stdc++.h>
using namespace std;
int n;
int q1[50100],q2[50100],q3[50100];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		int sum=0,l1=0,l2=0,l3=0;
		cin>>n;
		for(int i=1;i<=n;i++) 
		{
			int x,y,z;
			cin>>x>>y>>z;
			if(x>y && x>z)
			{
				q1[++l1]=min(x-y,x-z);
				sum+=x;
			}
			else if(y>x && y>z)
			{
				q2[++l2]=min(y-x,y-z);
				sum+=y;
			}
			else if(z>x && z>y)
			{
				q3[++l3]=min(z-x,z-y);
				sum+=z;
			}
			else if(x==y && x==z) sum+=x;
			else if(x==y) sum+=y;
			else if(y==z) sum+=z;
			else sum+=x;
		}
		if(l1<=n/2 && l2<=n/2 && l3<=n/2)
		{
			cout<<sum<<"\n";
			continue;
		}
		else
		{
			int j=0;
			if(l1>n/2)
			{
				sort(q1+1,q1+l1+1);
				while(l1>n/2)
				{
					l1--;
					sum-=q1[++j];
				}
			}
			if(l2>n/2)
			{
				sort(q2+1,q2+l2+1);
				while(l2>n/2)
				{
					l2--;
					sum-=q2[++j];
				}
			}
			if(l3>n/2)
			{
				sort(q3+1,q3+l3+1);
				while(l3>n/2)
				{
					l3--;
					sum-=q3[++j];
				}
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}