#include <iostream>
using namespace std;
string s;
int a[10];
bool f;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] < 'A')
		{
			a[s[i]-'0']++;
		}
	}
	for (int i = 9; i >= 0; i--)
	{
		if (i!=0 && a[i]!=0) f = 1;
		if (i == 0 && f==0)
		{
			cout << 0;
			break;
		}
		for (int j = 1; j <= a[i]; j++)
		{
			cout << i;
		}
	}
	return 0;
}
