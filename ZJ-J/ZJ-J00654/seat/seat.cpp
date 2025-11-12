#include<bits/stdc++.h>
using namespace std;
int n,m;
int c,r;
int shu;
int s;//小A 
int aa;
int ans;
int diji;//小A是第几个 
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	shu = n * m;
	cin >> s;
	for (int i = 2;i <= shu;i ++)
	{
		cin >> aa;
		if (aa > s)
		{
			ans ++;
		}
	}
	diji = ans + 1;
//	cout << "diji "<< diji << endl;
	if (diji % n != 0)
	{
		c = diji / n + 1;
		if (c % 2 == 0)
		{
			r = n - diji % n + 1;
		}
		else
		{
			r = diji % n;
		}
	}
	else
	{
		c = diji / n;
		if (c % 2 == 0)
		{
			r = 1;
		}
		else
		{
			r = n;
		}
	}
	cout << c << " " << r;
}
