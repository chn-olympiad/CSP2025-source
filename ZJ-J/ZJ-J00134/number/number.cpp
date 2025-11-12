#include <bits/stdc++.h>
using namespace std;
string s;
bool f = false;
int q, a[1000005];
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			a[q] = s[i] - 48; 
			q++;
		}
	}
	sort(a + 1, a + (q - 1) + 1);
	for(int i = q - 1; i >= 1; i--)
	{
		if(a[0] >= a[i] && a[0] <= a[i + 1] && !f)
		{
			cout << a[0];
			f = true;
		}
		cout << a[i];
	}
	return 0;
}