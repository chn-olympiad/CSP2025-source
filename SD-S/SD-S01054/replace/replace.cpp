#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 5;

int read()
{
	char ch = getchar();
	int x = 0 , f = 1;
	while(ch < '0' || ch > '9')
	{
		if(ch == '-') f = -f;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0' , ch = getchar();
	}
	return x * f;
}

void write(int x)
{
	if(x < 0)
	{
		x = -x;
		putchar('-');
	}
	if(x > 9) write(x / 10);
	putchar(x % 10 + '0');
}

int power(int a , int b)
{
	if(b == 0) return 1;
	int c = power(a , b >> 1);
	c = c * c;
	if(b & 1) c = c * a;
	return c;
}

int n , q , ans;

string a[N] , b[N];

signed main()
{
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	n = read() , q = read();
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> a[i] >> b[i];
	}
	if(n > 10000)
	{
		for(int i = 1 ; i <= q ; i ++) puts("0");
		exit(0);
	}
	while(q --)
	{
		string t1 , t2;
		ans = 0;
		cin >> t1 >> t2;
		for(int i = 1 ; i <= n ; i ++)
		{
			int l = t1.find(a[i]) , r = t2.find(b[i]);
			if(l == r && l < t1.size() && (t1.substr(0 , l) == t2.substr(0 , l)) && (t1.substr(l + a[i].size()) == t2.substr(l + a[i].size()))) ans ++;
		}
		cout << ans << '\n';
	}
	return 0;
}
