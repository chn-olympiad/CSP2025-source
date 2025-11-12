#include <iostream>
#include <string>
using namespace std;

int a[10];

int main()
{
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); ++i)
	{
		if ('1' <= s[i] <= '9') a[int(s[i]) - 48] ++;
	}
	for (int i = 9; i >= 0; --i)
	{
		while (a[i] != 0)
		{
			cout << i;
			a[i] --;
		}
	}
	return 0;
}
