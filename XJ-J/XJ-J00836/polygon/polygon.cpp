#include <iostream>
using namespace std;

int n, a[5010], pre[5010];
long long int answer;

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		pre[i] = pre[i - 1] + a[i];
	}
	for (int leftp = 1; leftp <= n; leftp++)
	{
		for (int rightp = 2 + leftp; rightp <= n; rightp++)
		{
			int maxn = -0x3f3f3f3f, sumn = 0;
			for (int i = leftp; i <= rightp; i++)
			{
				maxn = max(maxn, a[i]);
				sumn += a[i];
			}
			if (sumn > maxn * 2)
			{
				answer++;
				answer %= 998244353ll;
			}
		}
	}
	cout << answer << endl;
	return 0;
}

