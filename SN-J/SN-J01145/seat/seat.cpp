//韩心尧 SN-J01145 西安滨河学校 
#include <bits/stdc++.h>
#define int long long

using namespace std;

int n,m;
int a[110];
int pt,id;
int r,c;
int g,lst;
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n * m;i++)
	{
		cin >> a[i];
	}
	pt = a[1];
	sort(a + 1,a + n*m + 1);
	reverse(a + 1,a + n* m + 1);
	for (int i = 1;i <= n * m;i++)
	{
		if (a[i] == pt)
		{
			id = i;
			break;
		}
	}
	g = id / (n * 2);
	lst = id % (n * 2);
//	cout <<id <<" "<< g << " "<<lst<<endl;
	if (lst == 0)
	{
		c = g * 2;
		r = n;
	}
	else
	{
		c = g * 2 + ceil(lst * 1.0 / n);
		if (lst <= n)
		{
			r = lst;
		}
		else
		{
			r = n - lst % n + 1;
		}
	}
	cout << c << " "<<r;
	return 0;
}
