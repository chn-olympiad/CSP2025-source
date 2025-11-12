#include <iostream>
#include <cstdio>
using namespace std;
int a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	long long cnt=0;
	cin >> n >> k;
	for(int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	for(int i = 0;i < n;i++)
	{
		int m = 0;
		for(int j = i;j < n;j++)
		{
			m = m|a[j];
			if(m==k)
			{
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
} 
