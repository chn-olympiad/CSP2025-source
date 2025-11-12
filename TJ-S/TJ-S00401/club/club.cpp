#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	long long t;
	cin>>t;//输入t 
	long long n;
	long long c1=0,c2=0,c3=0;//c为三个社团满意度最大值各有多少  
	long long MAX[t];//n的最大值 
	for (int i = 1;i <= t;i++)
	{
		cin>>n;//输入n 
		long long max[n];
		long long a1[n],a2[n],a3[n];
		for (int j = 1;j <= n;j++)
		{
			//第j行判断开始 
			cin >>a1[j]>>a2[j]>>a3[j];//输入：a1，a2，a3
			if (a1[j]>=a2[j]&&a1[j]>=a3[j])
			{
				if ((c1+1)<=n/2)
				{
					max[j] = a1[j];
					c1++;
				}
				else if ((c1+1)>n/2)
				{
					for (int x = 1;x <= j;x++)
					{
						if (a1[j]>max[x])
						{
							max[x] = a1[j];
						}
					}
				}
			}
			else if (a2[j]>=a1[j]&&a2[j]>=a3[j])
			{
				if ((c2+1)<=n/2)
				{
					max[j] = a2[j];
					c2++;
				}
				else if ((c2+1)>n/2)
				{
					for (int x = 1;x <= j;x++)
					{
						if (a2[j]>max[x])
						{
							max[x] = a2[j];
						}
					}
				}
			}
			else if (a3[j]>=a1[j]&&a3[j]>=a2[j])
			{
				if ((c3+1)<=n/2)
				{
					max[j] = a3[j];
					c3++;	
				}
				else if ((c3+1)>n/2)
				{
					for (int x = 1;x <= j;x++)
					{
						if (a3[j]>max[x])
						{
							max[x] = a3[j];
						}
					}
				}
			}
			//第j行判断结束 
		}
		for (int j = 1;j <= n;j++)
		{
			MAX[i] += max[j];
		}
	}
	for (int i = 1;i <= t;i++)
	{
		cout << MAX[i]<<endl;
	}
	return 0;
}
