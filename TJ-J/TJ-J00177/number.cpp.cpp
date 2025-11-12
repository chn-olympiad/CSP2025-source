#include <iostream>
#include <algorithm>
using namespace std;

int a[1000110];

int main()
{
	string s;
	cin >> s;
	int cnt = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if(s[i] >= '0' && s[i] <= '9') 
		{
			cnt++;
			a[s[i] - '0']++;
		}
	}
	
	for (int i = 9; i >= 0; i--)
	{
		for (int j = 1; j <= a[i]; j++) cout << i;
	}
}
