#include <bits/stdc++.h>
using namespace std;
int main()
{
	freeopen("number.in","r",stdin);
	freeopen("number.out","w",stout);
	for (int i=0;i<=s;i++)
	{
		cin >> s;
		if (a[i]>=0&&a[i]<=9)
		{
			a[i]=s[i];
			if(a[i+1]>a[i])
			{
				sum=a[i+1];
				a[i+1]=a[i];
				a[i]=a[i+1];
			}
		}
		sum = 0;
	}
	for (int i=0;i<=100005;i++)
	{t","w",stdout);
	string s;
	int a[100005],sum=0;
		cout << a[i];
	}
	return 0;
}
