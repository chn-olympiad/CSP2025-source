#include <bits/stdc++.h>
using namespace std;
string a;
int b[1000005], z = 1;
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> a;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] >= '0' && a[i] <= '9')
		{
			b[z] = a[i]-'0';
			z++;
		}
	}
	sort(b+1, b+z+1);
	if (b[z] == 0)
	{
		cout << 0;
	}
	else
	{
		for (int i = z; i >= 2; i--) 
		{
			cout << b[i];
		}
	}
	return 0;
} 
