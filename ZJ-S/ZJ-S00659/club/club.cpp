#include<bits/stdc++.h>
using namespace std;

int n, t;
long long sum;

struct p
{
	short na, nb, nc;
};

bool cmpa(p x, p y)
{
	return max(x.nb, x.nc) - x.na < max(y.nb, y.nc) - y.na;
}

bool cmpb(p x, p y)
{
	return max(x.na, x.nc) - x.nb < max(y.na, y.nc) - y.nb;
}

bool cmpc(p x, p y)
{
	return max(x.nb, x.na) - x.nc < max(y.nb, y.na) - y.nc;
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--)
	{
		int suma = 0, sumb = 0, sumc = 0;
		sum = 0;
		p a[100001], b[100001], c[100001];
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			p x;
			cin >> x.na >> x.nb >> x.nc;
			if(x.na >= x.nb && x.na >= x.nc)
			{
				a[suma] = x;
				suma++;
			}
			else if(x.nb >= x.na && x.nb >= x.nc)
			{
				b[sumb] = x;
				sumb++;
			}
			else
			{
				c[sumc] = x;
				sumc++;
			}
		}
		for(int i = 0; i < suma; i++)
		{
			sum += a[i].na;
		}
		for(int i = 0; i < sumb; i++)
		{
			sum += b[i].nb;
		}
		for(int i = 0; i < sumc; i++)
		{
			sum += c[i].nc;
		}
		if(suma * 2 > n)
		{
			sort(a, a+suma, cmpa);
			for(int i = n/2; i < suma; i++)
			{
				sum += max(a[i].nb , a[i].nc) - a[i].na;
			}
		}
		else if(sumb * 2 > n)
		{
			sort(b, b+sumb, cmpb);
			for(int i = n/2; i < sumb; i++)
			{
				sum += max(b[i].na , b[i].nc) - b[i].nb;
			}
		}
		else if(sumc * 2 > n)
		{
			sort(c, c+sumc, cmpc);
			for(int i = n/2; i < sumc; i++)
			{
				sum += max(c[i].nb , c[i].na) - c[i].nc;
			}
		}
		cout << sum << endl;
		continue;
	}
}
