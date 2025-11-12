#include<iostream>
#include<cstdio>
#include <algorithm>
using namespace std;
struct node
{
	int x;
	int y;
	int z;
};
bool cmp(node x , node y)
{
	if(x.x != y.x)
	{
		return x.x > y.x;
	}
	else if(x.y != y.y)
	{
		return x.y > y.y;
	}
	else
	{
		return x.z > y.z;
	}
}
node a[100005];
int b[4];
int main()
{
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		for(int i = 1 ; i <= n ; i++)
		{
			cin >> a[i].x >> a[i].y >> a[i].z;
		}
		int sum = 0;
		sort(a+1 , a+n+1 , cmp);
		for(int i = 1 ; i <= n ; i++)
		{
			int maxn = -1;
			maxn = max(max(max(maxn , a[i].x) , a[i].y) , a[i].z);
		    if(maxn == a[i].x)
			{
				if(b[i] < n/2)
				{
					b[i]++;
					sum += a[i].x;
				}
				else
				{
					if(a[i].y > a[i].z)
					{
						sum += a[i].y;
						b[2]++;
					}
					else
					{
						sum += a[i].z;
						b[3]++;
					}
				}
			}
			if(maxn == a[i].y)
			{
				if(b[i] < n/2)
				{
					b[i]++;
					sum += a[i].y;
				}
				else
				{
					if(a[i].x > a[i].z)
					{
						sum += a[i].x;
						b[1]++ ;
					}
					else
					{
						sum += a[i].z;
						b[3]++;
					}
				}
			}
			if(maxn == a[i].z)
			{
				if(b[i] < n/2)
				{
					b[i]++;
					sum += a[i].z;
				}
				else
				{
					if(a[i].x > a[i].y)
					{
						sum += a[i].x;
						b[1]++ ;
					}
					else
					{
						sum += a[i].y;
						b[3]++;
					}
				}
			}
		}
		cout << sum;
	}
	return 0;
}

	


