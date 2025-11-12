#include<bits/stdc++.h>

using namespace std;

int ton[15];

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	string str;
	cin >> str;
	
	for(int i = 0; i < str.size(); i++)
	{
		if(str[i] < '0' && str[i] >'9')
		{
			continue;
		}
		ton[str[i] - '0']++;
	}
	
	for(int i = 9; i >= 0; i--)
	{
		while(ton[i] > 0)
		{
			ton[i]--;
			cout << i;
		}
	}
	
	return 0;
}
