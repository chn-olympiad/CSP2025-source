//SN-J00645 杨陈泽 西安高新第一中学
#include<bits/stdc++.h>
using namespace std;
int n , a[500020];
long long k;
int main()
{
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
	}
	int cnt = 0;
	for(int i = 1 ; i <= n ; i++)
	{
		if(a[i] == k)
		{
			cnt++;
			continue;
		}
		int x = a[i];
		for(int j = i+1 ; j <= n ; j++)
		{
			x ^= a[j];
			if(x == k)
			{
				cnt++;
				i = j;
				break;
			}
		}
	}
	cout << cnt;
	return 0;
}
