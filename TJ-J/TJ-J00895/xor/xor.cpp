#include <iostream>
#include <cstdio> 
using namespace std;
int a[500005];
int vis[500005];
int main()
{
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	int n , k;
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
	}
	int cnt = 0;
	for(int l = 1 ; l <= n ; l++)
	{
		for(int r = l ; r <= n ; r++)
		{
			int sum = 0;
			bool flag = true;
			for(int i = l ; i <= r ; i++)
			{
				sum ^= a[i];
				if(vis[i] == true)
				{
					flag = false;
				}
			}
			if(sum == k && flag == true)
			{
				cnt++;
				cout << l << ' ' << r << endl;
				for(int i = l ; i <= r ; i++)
				{
					vis[i] = true;
				}
			}
		}
	}
	cout << cnt;
	return 0;
}
