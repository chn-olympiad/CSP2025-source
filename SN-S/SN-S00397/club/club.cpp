#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

//写个注释证明我是自己写的 >:)
//不会了，趴 

int choose[100010];
int zero = 0, one = 0, two = 0;

struct m
{
	int one,two,three;
};

bool cmp1(m x, m y)
{
	return x.one < y.one;
}

bool cmp2(m x, m y)
{
	return x.two < y.two;
}

void next(int x)
{
	if (choose[x] == 2)
	{
		choose[x] = 0;
		two--;
		zero++;
		next(x+1);
	}
	else
	{
		if (choose[x] == 0)
		{
			zero--;
			one++;
		}
		if (choose[x] == 1)
		{
			one--;
			two++;
		}
		choose[x]++;
	}
}

int solve()
{
	int n;
	m member[100010];
	zero = 0; one = 0; two = 0;
	bool all_zero[3];
	
	int maxx = -1, sum;
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> member[i].one >> member[i].two >> member[i].three;
		choose[i] = 0;
	}
	
	zero = n;
	int sum_1 = 0;	
	
	if ((all_zero[1] == 0) && (all_zero[2] == 0))
	{
		sort(member + 1, member + n + 1, cmp1);
		for (int i = 1; i <= n / 2; i++)
		{
			sum_1 += member[i].one;
		}
		cout << sum_1;
		return 0;
	}
	
	while (true)
	{
		if (two == n)
		{
			break;
		}
		if ((zero > (n / 2)) || (one > (n / 2) || (two > (n / 2))))
		{
			next(1);
			continue;
		}
		
		sum = 0;
		
		for (int i = 1; i <= n; i++)
		{
			if (choose[i] == 0)
			{
				sum += member[i].one;
			}
			if (choose[i] == 1)
			{
				sum += member[i].two;
			}
			if (choose[i] == 2)
			{
				sum += member[i].three;
			}
		}
		
		if (maxx < sum)
		{
			maxx = sum;
		}
		
		next(1);
	}
	cout << maxx << endl;
	return 0; 
}

int main()
{
	freopen("club3.in","r",stdin);
	freopen("club3.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int x;
	cin >> x;
	
	for (int i = 1; i <= x; i++)
	{
		solve();
	}
	return 0;
} 
