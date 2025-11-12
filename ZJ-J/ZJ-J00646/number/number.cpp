#include<bits/stdc++.h>
using namespace std;

string s;
int n, cnt = 1;
int num[1000005];

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	n = s.size();
	for(int i = 0; i < n; i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			num[cnt] = s[i] - '0';
			cnt++;
		}
	}
	sort(num + 1, num + cnt);
	for(int i = cnt - 1; i >= 1; i--)
	{
		cout << num[i];
	} 
	
	return 0;
} 
