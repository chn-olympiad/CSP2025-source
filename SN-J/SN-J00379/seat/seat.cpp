#include <bits/stdc++.h>
using namespace std;
long long a,b,n[1000000],s,x,y;
int main()
{
	freopen("seat.in","r",p.in)
	freopen("seat.out","w",p.out)
	int x = 1,y = 1;
	cin >> a >> b;
	for (int i = 1; i <= a * b; i ++)
	{
		cin >> n[i];
		int s = n[1];
		if (s > n[i])
		{
			x ++;
			if(x > b)
			{
				y++;
				x = 1-x;
			}
		}
	}
	cout << x + 3 << " " << y;
	return 0;
}
