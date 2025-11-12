#include<bits/stdc++.h>
#define int long long

using namespace std;

struct node
{
	int num;
	int s;
	char flag;
};

operator<(node x, node y)
{
	return(x.num < y.num);
}

priority_queue <node> q;

int T;
int n;
int a[100001], b[100001], c[100001];
int f[100001];

int ans;
int cnta, cntb, cntc;

void input();
void init();
void calcu();

signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T--)
	{
		input();
		init();
		calcu();
		cout << ans << endl;
	}
}

void calcu()
{
	node u;
	char fu;
	
	while(!q.empty())
	{
		u = q.top();
		q.pop();
		fu = u.flag;
		if(fu == 'a' && cnta < n / 2 && f[u.s] == 0)
		{
			cnta++;
			ans += u.num;
			f[u.s] = 1;
		}
		if(fu == 'b' && cntb < n / 2 && f[u.s] == 0)
		{
			cntb++;
			ans += u.num;
			f[u.s] = 1;
		}
		if(fu == 'c' && cntc < n / 2 && f[u.s] == 0)
		{
			cntc++;
			ans += u.num;
			f[u.s] = 1;
		}
	}
}

void init()
{
	int i;
	int minn;
	node an, bn, cn;
	
	ans = 0;
	cnta = 0;
	cntb = 0;
	cntc = 0;
	an.flag = 'a';
	bn.flag = 'b';
	cn.flag = 'c';
	for(i = 1; i <= n; i++)
	{
		f[i] = 0;
		minn = min(a[i], min(b[i], c[i]));
		ans += minn;
		a[i] -= minn;
		b[i] -= minn;
		c[i] -= minn;
		an.num = a[i];
		an.s = i;
		bn.num = b[i];
		bn.s = i;
		cn.num = c[i];
		cn.s = i;
		q.push(an);
		q.push(bn);
		q.push(cn);
	}
}

void input()
{
	int i;
	
	cin >> n;
	for(i = 1; i <= n; i++)
	{
		cin >> a[i] >> b[i] >> c[i];
	}
}
