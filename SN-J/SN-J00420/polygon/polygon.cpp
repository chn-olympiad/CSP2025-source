#include<bits/stdc++.h>
using namespace std;
int ret[10010];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	int cnt = 0;
	for(int i = 1;i <= n;i++)
	{
		cin >> ret[i];
	}
	for(int qushu = 3;qushu <= n;qushu++)
	{
		for(int i = 0;i < n;i++)
		{
			if((max(ret[i],max(ret[i + 1], ret[i + 2]))) * 2 < (ret[i] + ret[i + 1] + ret[i + 2]))
			{
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
