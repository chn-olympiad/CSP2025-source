#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	string n;
	cin >> n;
	int a[1005],sum= 0,num = 1;
	for (int i = 0;i < n.length();i++)
	{
		if((n[i] < 'a') && (n[i] > 'z'))
		{
			a[num] = n[i];
			num++;
		}
	}
	int m = 1;
	sort(a+1,a+num+1);
	for(int i = sum;i >= 1;i--)
	{
		for(int j = 1;j < i;j++)
		{
			m *= 10;
		}
		sum += a[i] * m;
	}
	cout << sum;
	
	fclose(stdin);
	fclose(stdout);
    return 0;
}
