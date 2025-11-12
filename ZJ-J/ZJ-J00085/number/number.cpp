#include<bits/stdc++.h>
using namespace std;

string s;
int a[50];
bool o;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			a[s[i] - 48]++;
		}
	}
	for (int i = 9; i >= 0; i--)
	{
		if (a[i] != 0 && i != 0){
			o = 1;
			for (int j = 1; j <= a[i]; j++) cout << i ;
		}
		if (a[i] == 0) continue;
		if (i == 0 && o) 
			for (int j = 1; j <= a[i]; j++) cout << i ;
	}
	if (!o) cout << 0 << '\n';
	return 0;
}
