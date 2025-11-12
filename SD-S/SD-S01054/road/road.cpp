#include <bits/stdc++.h>
#define ll long long
#define PII pair <int , int>

using namespace std;

const int N = 1e4 + 5;

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

int n , m , k , f[N];

ll ans;

class edge
{
	public:
		int u , v , w;
		bool operator < (const edge& a) const
		{
			return a.w > w;
		}
}e[1000005];

int getf(int x)
{
	if(f[x] == x) return x;
	return f[x] = getf(f[x]);
}

signed main()
{
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	n = read() , m = read() , k = read();
//	if(k == 0)
//	{
		for(int i = 1 ; i <= n ; i ++) f[i] = i;
		for(int i = 1 ; i <= m ; i ++)
		{
			e[i].u = read() , e[i].v = read() , e[i].w = read();
		}
		sort(e + 1 , e + m + 1);
		for(int i = 1 ; i <= m ; i ++)
		{
			int u = getf(e[i].u) , v = getf(e[i].v);
			if(u == v) continue;
			ans += e[i].w;
			f[u] = v;
		}
		cout << ans << '\n';
//	}
	return 0;
}
