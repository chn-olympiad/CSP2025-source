#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int cnt[10];
char s[N];
int main()
{
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	cin >> s;
	int l = strlen(s);
	for(int i = 0; i <= l - 1; i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			cnt[s[i] - '0']++;
		}
	}
	for(int i = 9; i >= 0; i--)
	{
		for(int j = 1; j <= cnt[i]; j++)
		{
			cout << i;
		}
	}
	return 0;
}