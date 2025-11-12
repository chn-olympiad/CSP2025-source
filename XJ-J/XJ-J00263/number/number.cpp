#include <bits/stdc++.h>
using namespace std;
char s[1000005];
int a[1000005];
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	memset(s, 0, sizeof(s));
    cin >> s;
    int i = 0;
    int len = 0; 
    while (s[i] != 0)
    {
    	a[i] = s[i] - 48;
    	i++;
    	len++;
	}
	sort(a, a + len);
	for (int i = len - 1; i >= 0; i--)
	{
		cout << a[i];
	}
    return 0;
}
