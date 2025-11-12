#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std; 
int a[5005] = {};
int n = 0;

void f1()
{
	int leijia = 0;
	if(!(a[1]+a[2]+a[3]>2*a[3]))
	{
		cout<<0;
		return;
	}
	else if(!(a[1]+a[3]+a[3]>2*a[2]))
	{
		cout<<0;
		return;
	}
	else if(!(a[2]+a[3]+a[3]>2*a[1]))
	{
		cout<<0;
		return;
	}

	cout<<1;
}

void f2()
{
	int dp[5005] = {};
	int leijia = 0;
	dp[1] = a[1];
	for(int i = 2;i<=n;i++)
	{
		dp[i] = dp[i-1]+dp[i-2];
		if(2*dp[i]<dp[i-1]+dp[i-2])
		{
			leijia++;
		}
		else
		{
			dp[i] = a[i];
		}
	}

	cout<<leijia;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}


		f1();

	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
