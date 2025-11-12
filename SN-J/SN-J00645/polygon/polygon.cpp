//SN-J00645 杨陈泽 西安高新第一中学
#include<bits/stdc++.h>
using namespace std;
int a[5010] , n , cnt = 0;
long long qzh[5010];
int main()
{
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
	}
	sort(a + 1 , a + n + 1);
	for(int i = 1 ; i <= n ; i++)
	{
		qzh[i] = qzh[i-1] + a[i];
		a[i] *= 2;
	}
	for(int i = 3 ; i <= n ; i++)
	{
		bool flag = 1;
		for(int j = 0 ; j <= i-3 ; j++)
		{
			if(qzh[i] - qzh[j] < a[i])
			{
				cnt += j;
				flag = 0;
				break;
			}
		}
		if(flag)
		{
			cnt += i-2;
		}
	}
	cout << cnt;
	return 0;
}
