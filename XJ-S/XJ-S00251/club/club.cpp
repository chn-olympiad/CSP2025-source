#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node
{
	int c1,c2,c3;
}a[N];
int t,n,z1,z2,z3,s1[20005],s2[20005],s3[20005],m;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		z1=z2=z3=m=0;
		memset(s1,0,sizeof(s1));
		memset(s2,0,sizeof(s2));
		memset(s3,0,sizeof(s3));
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)
			cin>>a[i].c1>>a[i].c2>>a[i].c3;
		for(int i=1;i<=n;i++)
		{
			if(a[i].c1>=max(a[i].c2,a[i].c3))
				z1++,s1[min(a[i].c1-a[i].c2,a[i].c1-a[i].c3)]++,m+=a[i].c1;
			else if(a[i].c2>=max(a[i].c1,a[i].c3)) 
				z2++,s2[min(a[i].c2-a[i].c1,a[i].c2-a[i].c3)]++,m+=a[i].c2;
			else
				z3++,s3[min(a[i].c3-a[i].c2,a[i].c3-a[i].c1)]++,m+=a[i].c3;
		}
		cout<<z1<<' '<<z2<<' '<<z3<<' ';
		if(z1>n/2)
		{
			for(int i=0;i<=20000;i++)
			{
				if(z1-s1[i]<=n/2)
				{
					m-=(z1-n/2)*i;
					break;
				}
				z1-=s1[i];
				m-=s1[i]*i;
			}
		}
		if(z2>n/2)
		{
			for(int i=0;i<=20000;i++)
			{
				if(z2-s2[i]<=n/2)
				{
					m-=(z2-n/2)*i;
					break;
				}
				z2-=s2[i];
				m-=s2[i]*i;
			}
		}
		if(z3>n/2)
		{
			for(int i=0;i<=20000;i++)
			{
				if(z3-s3[i]<=n/2)
				{
					m-=(z3-n/2)*i;
					break;
				}
				z3-=s3[i];
				m-=s3[i]*i;
			}
		}
		cout<<m<<endl;
	}
	return 0;
}
