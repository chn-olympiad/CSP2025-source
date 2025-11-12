#include <bits/stdc++.h>
#define int long long
#define PII pair <int , int>

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

int t;

int n , ans;

class node
{
	public:
		PII v[4];
		void input()
		{
			v[0] = {0 , 0} , v[1] = {read() , 1} , v[2] = {read() , 2} , v[3] = {read() , 3};
			sort(v + 1 , v + 4);
		}
}a[N];

class st
{
	public:
		int i , th , val;
		st() { }
		st(int i , int th) : i(i) , th(th)
		{
			val = a[i].v[th].first - a[i].v[th - 1].first;
		}
		bool operator > (const st& x) const
		{
			return x.val < val;
		}
};

void solve()
{
	n = read() , ans = 0;
	priority_queue <st , vector <st> , greater <st> > cnt[4];
	for(int i = 1 ; i <= n ; i ++) a[i].input();
	for(int i = 1 ; i <= n ; i ++)
	{
		int t = a[i].v[3].second;
		cnt[t].push(st(i , 3));
		ans += a[i].v[3].first;
		if(cnt[t].size() > (n >> 1))
		{
			st k = cnt[t].top();
			cnt[t].pop();
			ans -= k.val;
			cnt[a[k.i].v[k.th - 1].second].push(st(k.i , k.th - 1));
		}
	}
	cout << ans << '\n';
}

signed main()
{
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	t = read();
	while(t --) solve();
	return 0;
}
