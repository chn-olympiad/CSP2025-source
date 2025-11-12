#include <iostream>
using namespace std;
int main()
{
	freopen("seat.in","r",exe);
	freopen("seat.out","w",exe);
	int n = 0,m = 0,a[101];
	cin >> n >> m;
	int s = n * m,d;
	for(int i = 1;i <= s;i++)
	{
		cin >> a[i];
	}
	d = a[1];
	for(int i = 1;i <= s;i++)
	{
		for(int j = 1;j < s;j++)
		{
			if(a[j + 1] > a[j])
			{
				int num;
				num = a[j];
				a[j] = a[j + 1];
				a[j + 1] = num;
			}
		}
	}
	for(int i = 1;i <= s;i++)
	{
		if(a[i] == d)
		{
			d = i;
		}
	}
	int c = d / n,r = d % n;
	c++;
	if(r == 0)
	{
		r++;
		c--;
	}     
	if(c % 2 == 1)
	{
		r = n;
	}                                                       
	else
	{
		r = n - r + 1;
	}
	cout << c << " " << r << endl;
	return 0;
}
