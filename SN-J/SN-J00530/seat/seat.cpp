#include <bits/stdc++.h>
using namespace std;
long long a[1000010];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int c,r,j = 0,cnt = 1;
	cin >> c >> r;
	for(int i=1;i <= c*r;i++)
	{
		cin >> a[i];
	}
	int u = a[1];
	sort(a+1,a+1+c*r);
	for(int i = c*r;i >= 1;i--)
	{
		if(a[i] == u)
		{
			j = i;
		}
	}
	while(j > c)
	{
		j = j - c;
		cnt++;
	}
	if (cnt % 2 == 1)
	{
		cout << cnt << " " << j;
	}
	else
	{
		cout << cnt << " " << c - j + 1;
	}
	return 0;
}
