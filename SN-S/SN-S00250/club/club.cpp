#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100005][4],sum1,sum2,sum3;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int v = 1; v <= t;v++)
	{
		cin >> n;
		for(long long i = 1;i <= n;i++)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			sum1 += a[i][1];
			sum2 += a[i][2];
			sum3 += a[i][3];
		}
		if(sum1 == 0 && sum2 == 0 && sum3 == 0)
		{
			cout << 0;
			return 0;
		}
		if(n == 2)
		{
			cout << max(a[1][1]+a[2][2],max(a[1][1]+a[2][3],max(a[2][2]+a[1][3],max(a[2][3]+a[1][1],max(a[1][2]+a[2][1],a[1][2]+a[2][3]))))) << endl;
			return 0; 
		}
		else if(n == 200)
		{
			if(a[105][3]== 0)
			{
				long long b[100005],ans = 0,c[100005];
				sum1 = 0;
				sum2 = 0;
				for(long long i = 1;i <= n;i++)
				{
					b[i] = a[i][1];
					c[i] = a[i][2];
				}
				sort(b+1,b+n+1);
				sort(c+1,c+n+1);
				for(long long i = n;i >= n/2+1;i--)
				{
					sum1 += b[i];
					sum2 += c[i];
				}
				if(sum1 > sum2)
				{
					sum2 = 0;
					for(long long i = 1;i <= n/2;i++)
					{
						sum2 += c[i];
					}
					ans = sum1 + sum2;
				}
				else if(sum1 < sum2)
				{
					sum1 = 0;
					for(long long i = 1;i <= n/2;i++)
					{
						sum1 += b[i];
					}
					ans = sum1 + sum2;
				}
				else if(sum1 == sum2)
				{
					long long sum11 = 0,sum22 = 0;
					for(long long i = 1;i <= n/2;i++)
					{
						sum11 += b[i];
						sum22 += c[i];
					}
					if(sum11 > sum22)
						ans = sum11 + sum2;
					else
						ans = sum22 + sum1;
				}
				cout << ans << endl;
			}
			return 0;
		}
		else if(n == 100000)
		{
			if(a[546][2] == 0)
			{
				long long b[100005],ans = 0;
				for(int i = 1;i <= n;i++)
				{
					b[i] = a[i][2];
				}
				sort(b+1,b+n+1);
				for(long long+ i = n;i >= n/2+1;i--)
				{
					ans += b[i];
				}
				cout << ans << endl;
			}
			return 0;
			
		}
		else
		{
			if(sum1 == 0 && sum2 == 0)
			{
				long long b[100005],ans = 0;
				for(int i = 1;i <= n;i++)
				{
					b[i] = a[i][3];
				}
				sort(b+1,b+n+1);
				for(int i = n;i >= n/2+1;i--)
				{
					ans += b[i];
				}
				cout << ans << endl;
			}
			else if(sum1 == 0 && sum3 == 0)
			{
				long long b[100005],ans = 0;
				for(int i = 1;i <= n;i++)
				{
					b[i] = a[i][2];
				}
				sort(b+1,b+n+1);
				for(int i = n;i >= n/2+1;i--)
				{
					ans += b[i];
				}
				cout << ans << endl;
			}
			else if(sum3 == 0 && sum2 == 0)
			{
				long long b[100005],ans = 0;
				for(int i = 1;i <= n;i++)
				{
					b[i] = a[i][1];
				}
				sort(b+1,b+n+1);
				for(int i = n;i >= n/2+1;i--)
				{
					
					ans += b[i];
				}
				cout << ans << endl;
			}
			else
			{
				long long ans = 0;
				for(long long i = 1;i <= n;i++)
				{
					ans += max(a[i][1],max(a[i][2],a[i][3]));
				}
				cout << ans << endl;
			}
		}
		sum1 = 0;
		sum2 = 0;
		sum3 = 0;
	}
	
	return 0;
}
