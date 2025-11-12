#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
bool cmp(int a,int b)
{
	if(a>b)
	{
		return a > b;
	}
	if(a < b)
	{
		return b > a;
	}
}

int main()
{
	
	int a[105] = {};

	
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++)
	{
		cin >> a[i];
	}
	int ri = a[1];
	int k = n*m;
	sort(a,a+k,cmp);
	for(int i = 1;i <= m;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			if(a[i] == ri)
			{
				cout << j << " " << i;
				break;
			}
			if(j == n)
			{
				j--;
			}
		}
	}
	
	return 0;
}
