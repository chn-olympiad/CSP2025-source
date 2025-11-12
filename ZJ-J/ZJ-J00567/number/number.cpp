#include <bits/stdc++.h>
using namespace std;

int a[1000005];
char s[1000005];
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	long long t = 1, len = strlen(s);
	for(long long i = 0; i < len; i++)
	{
		if(s[i] >= '0' && s[i] <='9')	
		{
			a[t] = s[i] - '0';
			t++;
		}	
	}
	sort(a + 1, a + t);
	for(long long i = t - 1; i >= 1; i--)
		printf("%d", a[i]);
	return 0;
}

