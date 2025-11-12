#include <bits/stdc++.h>
using namespace std;
string s;
long long a[1000003];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int sum = 0;
	int n = s.size();
	for (int i = 0;i < n;i++)
	{

		if (s[i] - 48 >= 0 and s[i] - 48 < 10)
		{
			a[i] = s[i] - 48;
		}
		else
		{
			sum++;
			continue;
		}
	}
	sort (a,a + n);
	for (int i = n - 1;i >= sum;i--)
	{
		cout << a[i];
	}
	return 0;
}
