#include <bits/stdc++.h>
using namespace std;
int n, k, a[500002];
void tsxzb()
{
	int sum = 0;
	if(k == 0)
	{
		int i = 1;
		while(i <= n)
			if(a[i] == 0)
				sum++, i++;
			else
			{
				int j = i+1;
				while(j <= n && a[j] == 0)
					j++;
				if(a[j] == 1)
					sum += max(j-i-1, 1);
				else 
				{
					sum += j-i-1;
					break;
				}
				i = j+1;	
			}
	}
	else 
		for(int i = 1; i <= n; i++)
			if(a[i] == 1)
				sum++;
	cout << sum << endl;
}
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	bool b = 1, bl = 1, bll = 1;
	for(int i = 1; i <= n; i ++)
	{
		scanf("%d", &a[i]);
		if(a[i] > 255) b = 0;
		else if(a[i] > 1) bl = 0;
		else if(a[i] == 0) bll = 0;	
	}
	if(b && bl && bll)//A
	{
		cout << n/2 << endl;
		return 0;
	}
	if(b && bl)//B
	{
		tsxzb();
		return 0;
	}
	return 0;
}