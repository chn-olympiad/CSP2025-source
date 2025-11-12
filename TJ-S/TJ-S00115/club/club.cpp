#include<bits/stdc++.h>
using namespace std;

int t, n;

struct node
{
	int a, b, c, book = 0;
};

node hp[100005], hp2[100005], hp3[100005];

bool cmp1(node x, node y)
{
	return x.a > y.a;
}

bool cmp2(node x, node y)
{
	return x.b > y.b;
}

bool cmp3(node x, node y)
{
	return x.c > y.c;
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	int total = 0;
	while(t--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			cin >> hp[i].a >> hp[i].b >> hp[i].c;
			hp2[i].a = hp[i].a, hp2[i].b = hp[i].b, hp2[i].c = hp[i].c;
			hp3[i].a = hp[i].a, hp3[i].b = hp[i].b, hp3[i].c = hp[i].c;
		}
		int suma = 0, sumb = 0, sumc = 0;
		sort(hp + 1, hp + n + 1, cmp1);
		sort(hp2 + 1, hp2 + n + 1, cmp2);
		sort(hp3 + 1, hp3 + n + 1, cmp3);
		for(int i = 1; i <= n / 2; i++)
		{
			suma += hp[i].a;
			sumb += hp2[i].b;
			sumc += hp3[i].c;
		}
		if(suma >= sumb && suma >= sumc)
		{
			total += suma;
			if(n % 2 == 0)
			{
				for(int i = n / 2; i <= n; i++)
				{
					total += hp[i].b;
				}
			}
			else
			{
				for(int i = n / 2; i < n; i++)
				{
					total += hp[i].b;
				}
			}
		}
		if(sumb >= suma && sumb >= sumc)
		{
			total += sumb;
			if(n % 2 == 0)
			{
				for(int i = n / 2; i <= n; i++)
				{
					total += hp[i].a;
				}
			}
			else
			{
				for(int i = n / 2; i < n; i++)
				{
					total += hp[i].a;
				}
			}
		}
		cout << total;
	}
	return 0;
}
