#include<bits/stdc++.h>
using namespace std;
struct c
{
	int a1,a2,a3;
	int z1,z2;
	int b1,b2;
	int cc;
};
bool cmp(c x,c y)
{
	return x.cc>y.cc;
}
c a[100005];
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
		int cnt1=0;
		int cnt2=0;
		int cnt3=0;
		long long cnt=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			if(a[i].a1>=a[i].a2&&a[i].a2>=a[i].a3)
			{
				a[i].z1=a[i].a1;
				a[i].z2=a[i].a2;
				a[i].b1=1;
				a[i].b2=2;
			}
			else if(a[i].a2>=a[i].a3&&a[i].a3>=a[i].a1)
			{
				a[i].z1=a[i].a2;
				a[i].z2=a[i].a3;
				a[i].b1=2;
				a[i].b2=3;
			}
			else if(a[i].a1>=a[i].a3&&a[i].a3>=a[i].a2)
			{
				a[i].z1=a[i].a1;
				a[i].z2=a[i].a3;
				a[i].b1=1;
				a[i].b2=3;
			}
			else if(a[i].a2>=a[i].a1&&a[i].a1>=a[i].a3)
			{
				a[i].z1=a[i].a2;
				a[i].z2=a[i].a1;
				a[i].b1=2;
				a[i].b2=1;
			}
			else if(a[i].a3>=a[i].a1&&a[i].a1>=a[i].a2)
			{
				a[i].z1=a[i].a3;
				a[i].z2=a[i].a1;
				a[i].b1=3;
				a[i].b2=1;
			}
			else if(a[i].a3>=a[i].a2&&a[i].a2>=a[i].a1)
			{
				a[i].z1=a[i].a3;
				a[i].z2=a[i].a2;
				a[i].b1=3;
				a[i].b2=2;
			}
			a[i].cc=a[i].z1-a[i].z2;
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++)
		{
			if(cnt1>=n/2)
			{
				if(a[i].b1!=1)
				{
					cnt+=a[i].z1;
				}
				else
				{
					cnt+=a[i].z2;
				}
			}
			else if(cnt2>=n/2)
			{
				if(a[i].b1!=2)
				{
					cnt+=a[i].z1;
				}
				else
				{
					cnt+=a[i].z2;
				}
			}
			else if(cnt3>=n/2)
			{
				if(a[i].b1!=3)
				{
					cnt+=a[i].z1;
				}
				else
				{
					cnt+=a[i].z2;
				}
			}
			else
			{
				cnt+=a[i].z1;
				if(a[i].b1==1)
				{
					cnt1++;
				}
				if(a[i].b1==2)
				{
					cnt2++;
				}
				if(a[i].b1==3)
				{
					cnt3++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
 } 
