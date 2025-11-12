#include <bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool cmp(int a,int b)
{
	return a > b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n * m;i++)
	{
		cin>>a[i];
	}
	int a1 = a[1],pos;
	sort(a + 1,a + n * m + 1,cmp);
	for(int i = 1;i <= n * m;i++)
	{
		if(a[i] == a1)
		{
			pos = i;
		}
	}
	int f,g;
	if(n == 1)
	{
		f = pos,g = 1;
		cout<<f<<" "<<g;
		return 0;
	}
	else
	{
		if(pos % n == 0)
		{
			f = pos / n;
		}
		else
		{
			f = pos / n + 1;
		}
	}
	if(f % 2 == 0)
	{
		if(pos % n == 0)
		{
			g = 1;
		}
		else
		{
			g = n - pos % n + 1;
		}
	}
	else
	{
		if(pos % n == 0)
		{
			g = n + pos % n;
		}
		else
		{
			g = pos % n;
		}
	}
	cout<<f<<' '<<g;
	return 0;
}
