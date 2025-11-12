#include <iostream>
#include <cstdio>
using namespace std;
int a[10],cnt;


int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
		if (s[i] >= '0' && s[i] <= '9')
		{
			a[s[i]-'0']++;
			cnt++;
		}
	for (int i = 9; i >= 0; i--)
		if (a[i])
			for (int j = 1; j <= a[i]; j++)
				cout << i;
		
	return 0;
}
