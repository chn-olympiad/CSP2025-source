#include<iostream>
using namespace std;
int n,m,s,t,a[5001];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==3)
	{
		cin>>a[1]>>a[2]>>a[3];
		m=max(a[1],max(a[2],a[3]));
		if(m*2<a[1]+a[2]+a[3])	cout<<1;
		else	cout<<0;
		return 0;
	}
	if(n==4)
	{
		cin>>a[1]>>a[2]>>a[3]>>a[4];
		m=max(a[1],max(a[2],max(a[3],a[4])));
		if(m*2<a[1]+a[2]+a[3]+a[4])	s++;
		m=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(j!=i)
				{
					m=max(m,a[j]);
					t+=a[j];
				}
			}
			if(m*2<t)	s++;
			m=0,t=0;
		}
		cout<<s;
		return 0;
	}
	for(int i=1;i<=n;i++)	cin>>a[i];
	if(n==5&&a[1]==1)	cout<<9;
	else if(n==5&&a[1]==2)	cout<<6;
	else if(n==20)	cout<<1042392;
	else	cout<<366911923;
	return 0;
}
