#include <iostream>
using namespace std;
string s;
int a[1000000],n,m;
int main()
{
	freopen("number.in","r",exe);
	freopen("number.out","w",exe);
	cin >> s;
	n = s.size();
	for(int i = 0;i < n;i++)
	{
		if(s[i] - '0' >= 0 && s[i] - '0' <= 9)
		{
			m++;
			a[m] = s[i] - '0';
		}
	}
	for(int i = 1;i <= m;i++)
	{
		for(int j = 1;j < m;j++)
		{
			if(a[j + 1] > a[j])
			{
				n = a[j];
				a[j] = a[j + 1];
				a[j + 1] = n;
			}
		}
	}
	for(int i = 1;i <= m;i++)
	{
		cout << a[i];
	}
	cout << endl;
	return 0;
}

