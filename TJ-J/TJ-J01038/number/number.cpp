#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string n;
	cin >> n;
	int a[100009] = {0};
	int len = 0;
	for (int i = 0; i < n.length(); i++)
	{
		if (n[i] >= '0' && n[i] <= '9')
		{
			a[len] = (int)(n[i] - '0');
			len++;
		}
	}
	sort(a, a + len);
	for (int i = len - 1; i >= 0; i--)
	{
		cout << a[i];
	}
	return 0;
}
