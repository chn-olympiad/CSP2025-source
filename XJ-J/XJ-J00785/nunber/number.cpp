#include <bits/stdc++.h>
using namespace std;
int z,n[15];
string a;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> a;
	for (int i = 0;i <= sizeof(a);i++)
	{
		cin >> a[i];
		if (a[i] == '0')
		{
			n[0]++;
		}
		else if (a[i]== '1')
		{
			n[1]++;
		}
		else if (a[i] == '2')
		{
			n[2]++;
		}
		else if (a[i] == '3')
		{
			n[3]++;
		}
		else if (a[i] == '4')
		{
			n[4]++;
		}
		else if (a[i] == '5')
		{
			n[5]++;
		}
		else if (a[i] == '6')
		{
			n[6]++;
		}
		else if (a[i] == '7')
		{
			n[7]++;
		}
		else if (a[i] == '8')
		{
			n[8]++;
		}
		else if (a[i] == '9')
		{
			n[10]++;
		}
	}
	for (int j = 9;j >= 0;j--)
	{
		while(n[j] > 0)
		{
			cout << j;
			n[j]--;
		}
	}
	return 0;
} 
