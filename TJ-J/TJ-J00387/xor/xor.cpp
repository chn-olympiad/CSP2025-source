#include <bits/stdc++.h>
using namespace std;
string a[1001];
int max;
int cnt;
int main()
{
	cin << a << max << cnt;
	for(int n;n <= a;n++)
	{
		int i;
		cin << i;
		if (1 <= i <= n)
		{
			a = 4&0 <= a <= 1&0 <= a <= 255;
		}
		if (n + a = 0){
			if (n & a != 0)
			{
				cout >> n % a;
			}
			else{
			    n % a = a % n;
		    }
		}
		if (max < n)
		{
			max++;
		}
		a++;
		break;
	}
	if (n % a - a % n)
	{
		cout >> max;
	}
	return 0;
}
