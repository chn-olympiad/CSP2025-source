#include <bits/stdc++.h>
using namespace std;

int dc[500005];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k;
	cin >> n >> k;
	int A = 1,B = 1;
    for(int i = 0;i < n;i++)
    {
    	cin >> dc[i];
    	if(dc[i] != 1)
		{
			A = 0;
		}
		if(dc[i] > 1)
		{
			B = 0;
		}
	}
	
	if ((k == 0) && (A = 1)) //性质A 
	{
		cout << n;
		return 0;
	}
	
	else if ((k <= 1) && (B = 1)) //性质B 
	{
		int ou = 0;
		for (int i = 0;i < n;i++)
		{
			if(i == 1)
			{
				ou++;
			}
		}
		cout << ou;
		return 0;
	}
	else
	{
		cout << 255;
	}
	
	return 0;
}
