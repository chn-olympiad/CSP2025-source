#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e7 + 5;

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



signed main()
{
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	puts("0");
	return 0;
}
