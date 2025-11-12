#include <bits/stdc++.h>
using namespace std;

string s, new_s;

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> s;
	
	for (size_t i = 0; i < s.size(); ++i)
	{
		if (s[i] >= '0' and s[i] <= '9')
		{
		
			new_s += s[i];
		}
	}
	
	sort(new_s.begin(), new_s.end());
	// Íü¼ÇÁË¡­¡­
	for (int i = new_s.size() - 1; i >= 0; --i)
	{
		cout << new_s[i];
	 } 
	cout << endl;
	return 0;
 } 
