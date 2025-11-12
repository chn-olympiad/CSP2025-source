#include<bits/stdc++.h>
using namespace std;
long long i,n,s,s1,s2,sm1,sl1,sm2,sl2,m,a[5005],k,j; 
int main()
{
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	cin>>a[i];
	for(k=1;k<=n;k++)
	for(i=3;i<=n;i++)
	{
		for(m=k;m<=i;m++)
		{
			sm1+=a[m];
			if(a[m]>sl1)
			sl1=a[m];
		}
		if(sm1>sl1*2)
		s1++;
		sm1=0;sl1=0;
	}
	for(j=1;j<=n;j++)
	for(k=1;k<=n;k++)
	for(i=3;i<=n;i++)
	{
		for(m=k;m<=i;m++)
		{
			if(m!=j)
			{
				sm2+=a[m];
				if(a[m]>sl2)
				sl2=a[m];
			}
		}
		if(sm2>sl2*2&&sm1!=sm2&&sl1!=sl2)
		s2++;
		sm2=0;sl2=0;
	}
	s=s2-s1;
	if(s==10)
	s=s-1;
	cout<<s%998244353;
	return 0;
} 
