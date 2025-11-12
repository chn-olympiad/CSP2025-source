#include <iostream>
#include <vector>
using namespace std;

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	vector <int> a(n, 0);
	for (int i = 0; i < n; i++) cin >> a[i];
	int cnt = 0;
	int len = 0;
	for (int i = 0; i < n; i++)
	{
		len = 0;
		bool f = false;
		for (int j = 0; j < n - i; j++)
		{
			if (a[i] == k)
			{
				cnt++;
				break;
			}
			int sum = a[i];
			len = j;
			for (int x = i + 1; x <= i + j; x++)
			{
				sum = sum ^ a[x];
			}
			if (sum == k)
			{
				f = true;
				cnt++;
				break;
			}
		}
		if (f)
		{
			i += len;
		}
	}
	cout << cnt;
	return 0;
}
