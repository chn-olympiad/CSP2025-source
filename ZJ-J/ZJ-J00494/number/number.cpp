#include<bits/stdc++.h>
using namespace std;
string n;
long long a[15];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> n;
	for(int i = 0; i < n.size(); i++)
	{
		if (n[i]-'0' >= 0 && n[i]-'0' <= 9)
		{
			a[n[i] - '0']++;
		}
	}
	for (int i = 9; i >= 0; i--)
	{
		for (int j = 1; j <= a[i]; j++)
		{
			cout << i;
		}
	}
	return 0;
}
