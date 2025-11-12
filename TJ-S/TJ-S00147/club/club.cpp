#include<iostream>
#include<algorithm>
using namespace std;

int n, a[100005][5], T;
int tans, ans, cnt[5], cha[20005], mx[100005], num[100005];
bool flag;

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> T;
	while(T--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			int x = 0, y = 1;
			for(int j = 1; j <= 3; j++)
			{
				cin >> a[i][j];
				if(a[i][j] > x)
				{
					x = a[i][j];
					y = j;
				}
			}
			mx[i] = x, num[i] = y;
		}
		
		ans = 0, tans = 0, flag = true;
		for(int i = 1; i <= 3; i++) cnt[i] = 0;
		for(int i = 0; i <= 20000; i++) cha[i] = 0;
		for(int i = 1; i <= n; i++)
		{
			cnt[num[i]]++;
			tans += mx[i];
		}
		for(int i = 1; i <= 3; i++)
		{
			if(cnt[i] > n / 2)
			{
				int dis = cnt[i] - (n / 2);
				for(int j = 1; j <= n; j++)
				{
					if(num[j] == i)
					{
						if(i == 1) cha[min(a[j][1] - a[j][2], a[j][1] - a[j][3])]++;
						if(i == 2) cha[min(a[j][2] - a[j][1], a[j][2] - a[j][3])]++;
						if(i == 3) cha[min(a[j][3] - a[j][2], a[j][3] - a[j][1])]++;
					}
				}
				int dsum = 0;
				for(int j = 0; j <= 20000; j++)
				{
					if(dis >= cha[j])
					{
						tans -= cha[j] * j;
						dis -= cha[j];
					}
					else
					{
						tans -= cha[j] * dis;
						break;
					}
				}
				ans = max(ans, tans);
				flag = false;
				break;
			}
		}
		if(flag == true) ans = tans;
		cout << ans << endl;
	}
	return 0;
}
