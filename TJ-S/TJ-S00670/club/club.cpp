#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int t,a[100005][10];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i = 1;i<=t;i++)
	{
		int n;
		cin>>n;
		for(int j = 1;j<=n;j++)
		{
			for(int k = 1;k<=3;k++)
			{
				cin>>a[j][k];
			}
		}
		int sum = 0;
		int num1 = 0,num2 = 0,num3 = 0;
		for(int j = 1;j<=n;j++)
		{
			if(num1 < n/2+1 && num2 < n/2+1 && num3 < n/2+1)
			{
				if(a[j][1]>a[j][2]>a[j][3] || a[j][1]>a[j][3]>a[j][2])
				{
					num1++;
					sum+=a[j][1];
				}
				else if(a[j][2]>a[j][1]>a[j][3] || a[j][2]>a[j][3]>a[j][1])
				{
					num2++;
					sum+=a[j][2];
				}
				else if(a[j][3]>a[j][1]>a[j][2] || a[j][3]>a[j][2]>a[j][1])
				{
					num3++;
					sum+=a[j][3];
				}
			}
			else if(num1 <n/2+1 && num2 <n/2+1)
			{
				if(a[j][1]>a[j][2])
				{
					num1++;
					sum+=a[j][1];
				}
				else if(a[j][2]>a[j][1])
				{
					num2++;
					sum+=a[j][2];
				}
			}
			else if(num1 <n/2+1 && num3 <n/2+1)
			{
				if(a[j][1]>a[j][3])
				{
					num1++;
					sum+=a[j][1];
				}
				else if(a[j][3]>a[j][1])
				{
					num3++;
					sum+=a[j][3];
				}
			}
			else if(num2<n/2+1 && num3<n/2+1)
			{
				if(a[j][2]>a[j][3])
				{
					num2++;
					sum+=a[j][2];
				}
				else if(a[j][3]>a[j][2])
				{
					num3++;
					sum+=a[j][3];
				}
			}
			else if(num1<n/2+1)
			{
				num1++;
				sum+=a[j][1];
			}
			else if(num2<n/2+1)
			{
				num2++;
				sum+=a[j][2];
			}
			else if(num3<n/2+1)
			{
				num3++;
				sum+=a[j][3];
			}
		}
		cout<<sum<<endl;
	} 
	return 0;
}
