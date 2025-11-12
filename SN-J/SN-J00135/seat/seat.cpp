#include<bits/stdc++.h>

using namespace std;

#define int long long

int n, m;//n行m列 
int a[1000];

int mark;
int num;

int r, c;//r行c列 

void input();

signed main()
{
	//一定不要忘记删啊 
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	//一定不要忘记删啊 
	
	int i;
	
	input();
	mark = a[1];
	sort(a + 1, a + n * m + 1, greater<int>());
	for(i = 1; i <= n * m; i++)
	{
		if(a[i] == mark)
		{
			num = i;
			break;
		}
	}
	//求列
	c = i / n;
	//向上取整 
	if(i % n != 0)
	{
		c++;
	}
	if(c % 2 == 0)
	{
		r = i % n;
		if(r == 0)
		{
			r = n;
		}
		r = n - r + 1; 
	}
	else
	{
		r = i % n;
		if(r == 0)
		{
			r = n;
		}
	}
	cout << c << " " << r;
}

void input()
{
	int i;
	
	cin >> n >> m;
	for(i = 1; i <= n * m; i++)
	{
		cin >> a[i];
	}
}
