#include<bits/stdc++.h>
using namespace std;
int n,i,j,a[5004],x;
int c(int s,int t)
{
	long long z=1;
	for(int k=1;k<=t;k++)
	{
		z*=s+1-k;
		z/=k;
		z%=998244353;
	}
	return z;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n;i++)
		for(j=2;j<=n;j++)
			if(a[j-1]>a[j])
				swap(a[j-1],a[j]);
	if(n==3)
	{
		if(a[1]+a[2]>a[3])cout<<1;
		if(a[1]+a[2]<=a[3])cout<<0;
	}
	else if(n==4)
	{
		x=0;
		if(a[1]+a[2]>a[3])x++;
		if(a[1]+a[2]>a[4])x++;
		if(a[1]+a[3]>a[4])x++;
		if(a[2]+a[3]>a[4])x++;
		if(a[1]+a[2]+a[3]>a[4])x++;
		cout<<x;
	}
	else if(n==5)
	{
		x=0;
		if(a[1]+a[2]>a[3])x++;
		if(a[1]+a[2]>a[4])x++;
		if(a[1]+a[2]>a[5])x++;
		if(a[1]+a[3]>a[4])x++;
		if(a[1]+a[3]>a[5])x++;
		if(a[1]+a[4]>a[5])x++;
		if(a[2]+a[3]>a[4])x++;
		if(a[2]+a[3]>a[5])x++;
		if(a[2]+a[4]>a[5])x++;
		if(a[3]+a[4]>a[5])x++;
		if(a[1]+a[2]+a[3]>a[4])x++;
		if(a[1]+a[2]+a[3]>a[5])x++;
		if(a[1]+a[2]+a[4]>a[5])x++;
		if(a[1]+a[3]+a[4]>a[5])x++;
		if(a[2]+a[3]+a[4]>a[5])x++;
		if(a[1]+a[2]+a[3]+a[4]>a[5])x++;
		cout<<x;
	}
	else if(n==6)
	{
		x=0;
		if(a[1]+a[2]>a[3])x++;
		if(a[1]+a[2]>a[4])x++;
		if(a[1]+a[2]>a[5])x++;
		if(a[1]+a[2]>a[6])x++;
		if(a[1]+a[3]>a[4])x++;
		if(a[1]+a[3]>a[5])x++;
		if(a[1]+a[3]>a[6])x++;
		if(a[1]+a[4]>a[5])x++;
		if(a[1]+a[4]>a[6])x++;
		if(a[1]+a[5]>a[6])x++;
		if(a[2]+a[3]>a[4])x++;
		if(a[2]+a[3]>a[5])x++;
		if(a[2]+a[3]>a[6])x++;
		if(a[2]+a[4]>a[5])x++;
		if(a[2]+a[4]>a[6])x++;
		if(a[3]+a[4]>a[5])x++;
		if(a[3]+a[4]>a[6])x++;
		if(a[3]+a[5]>a[6])x++;
		if(a[4]+a[5]>a[6])x++;
		if(a[1]+a[2]+a[3]>a[4])x++;
		if(a[1]+a[2]+a[3]>a[5])x++;
		if(a[1]+a[2]+a[3]>a[6])x++;
		if(a[1]+a[2]+a[4]>a[5])x++;
		if(a[1]+a[2]+a[4]>a[6])x++;
		if(a[1]+a[2]+a[5]>a[6])x++;
		if(a[1]+a[3]+a[4]>a[5])x++;
		if(a[1]+a[3]+a[4]>a[6])x++;
		if(a[1]+a[3]+a[5]>a[6])x++;
		if(a[1]+a[4]+a[5]>a[6])x++;
		if(a[2]+a[3]+a[4]>a[5])x++;
		if(a[2]+a[3]+a[4]>a[6])x++;
		if(a[2]+a[4]+a[5]>a[6])x++;
		if(a[3]+a[4]+a[5]>a[6])x++;
		if(a[1]+a[2]+a[3]+a[4]>a[5])x++;
		if(a[1]+a[2]+a[3]+a[4]>a[6])x++;
		if(a[1]+a[2]+a[3]+a[5]>a[6])x++;
		if(a[1]+a[2]+a[4]+a[5]>a[6])x++;
		if(a[1]+a[3]+a[4]+a[5]>a[6])x++;
		if(a[2]+a[3]+a[4]+a[5]>a[6])x++;
		if(a[1]+a[2]+a[3]+a[4]+a[5]>a[6])x++;
		cout<<x;
	}
	else
	{
		x=0;
		for(j=3;j<=n;j++)
			x+=c(n,j);
		cout<<x;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
