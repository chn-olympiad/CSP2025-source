#include<bits/stdc++.h>
using namespace std;
int a[10];
string s;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for (int i = 0; i <= s.size() - 1; i++)
		if (s[i] >= '0' && s[i] <= '9') a[s[i] - '0']++;
	for (int j = 9; j >= 0; j--)
		if (a[j] != 0)
			for (int k = 0; k < a[j]; k++) cout << j;
	//for (int j = 0; j <= 9; j++) cout << endl << a[j] << " " << j;
	return 0;
}
