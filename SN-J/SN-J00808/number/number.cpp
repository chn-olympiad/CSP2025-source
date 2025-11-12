#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int a[15] = {};
	for (int i = 0 ; i<=s.length() ; i++)
	{
		if (s[i]=='1') a[1]++;
		else if (s[i]=='2') a[2]++;
		else if (s[i]=='3') a[3]++;
		else if (s[i]=='4') a[4]++;
		else if (s[i]=='5') a[5]++;
		else if (s[i]=='6') a[6]++;
		else if (s[i]=='7') a[7]++;
		else if (s[i]=='8') a[8]++;
		else if (s[i]=='9') a[9]++;
		else if (s[i]=='0') a[0]++;
		else continue;		
	}
	for (int j = 9 ;j >=0 ; j--)
	{
		if (a[j]>0)
		{
			for (int i = 1 ; i<=a[j];i++)
			{
				cout << j;
			}
		}
	}
	return 0;
}
