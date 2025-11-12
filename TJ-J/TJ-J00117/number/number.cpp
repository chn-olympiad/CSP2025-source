#include <bits/stdc++.h>
using namespace std;

string s;

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> s;
	sort(s.rbegin(), s.rend());
	for (const auto& ch : s)
	{
		if (isdigit(ch))
		{
			cout << ch;
		}
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
