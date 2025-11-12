#include <bits/stdc++.h>
#define int long long
using namespace std;
int re()
{
	int sum = 0, p = 1;
	char ch = getchar();
	while(!isdigit(ch)){if(ch == '-')p = -1; ch = getchar();}
	while(isdigit(ch)){sum = sum * 10 + (ch - '0');ch = getchar();}
	return sum * p;
}
const int N = 1e6 + 10;
int cnt, a[N];
char s[N];
signed main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> (s + 1);
	int n = strlen(s + 1);
	for(int i = 1; i <= n; i++)
		if(isdigit(s[i])) a[++cnt] = s[i] - '0';
	sort(a + 1, a + 1 + cnt);
	for(int i = cnt; i >= 1; i--) cout << a[i];
	return 0;
}