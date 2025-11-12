#include<bits/stdc++.h>
using namespace std;
void fre()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
}
int n;
int m;
int a[105];
int main()
{
	fre();
	cin>>n>>m;
	for(int i = 1; i<=n*m; i++)
	{
		cin>>a[i];
		a[i] = -a[i];
	}
	int tmp = a[1];
	int w = 0;
	int x = 1;
	int y = 1;
	bool h = true;
	sort(a+1,a+n*m+1);
	for(int i = 1; i<=n*m; i++)
	{
		if(a[i] == tmp)
		{
			cout<<y<<' '<<x;
			break;
		}
		if(h)
		{
			if(x == n)
			{
				y++;
				h = false;
			}
			else
			{
				x++;
			}
		}
		else
		{
			if(x == 1)
			{
				y++;
				h = true;
			}
			else
			{
				x--;
			}
		}
	}
	return 0;
}
