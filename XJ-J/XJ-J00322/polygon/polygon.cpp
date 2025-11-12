#include<bits/stdc++.h>
using namespace std;
int main()

{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n];
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}/*
	for(int i=3;i<=m;i++)
	{
		for(int j=3;j<=m;j++)
		{
			
		}
	}
	/*for(int i=3;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			for(int k=1;k<=n;k++)
		}
	}*/
	//if(a)
	//	cout<<sum;

	if(a[1]+a[2]>a[3])
		sum++;
		if(a[1]+a[2]>a[4])
		sum++;
			if(a[1]+a[2]>a[5])
		sum++;
			if(a[1]+a[3]>a[4])
		sum++;
			if(a[1]+a[3]>a[5])
		sum++;
			if(a[1]+a[4]>a[5])
		sum++;
			if(a[3]+a[2]>a[4])
		sum++;
			if(a[4]+a[2]>a[5])
		sum++;
			if(a[2]+a[3]>a[5])
		sum++;
			if(a[3]+a[4]>a[3])
		sum++;
			if(a[1]+a[2]+a[3]>a[4])
		sum++;
			if(a[1]+a[2]+a[4]>a[5])
		sum++;	
			if(a[1]+a[3]+a[4]>a[5])
		sum++;
			if(a[3]+a[2]+a[4]>a[5])
		sum++;
			if(a[1]+a[2]+a[4]+a[3]>a[5])
		sum++;
		cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 	
