#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

bool choose[5007] = {0,1,1,0};

//放个注释证明这是我自己写的  >:) 

void next(int x)
{
	if (choose[x] == true)
	{
		choose[x] = false;
		next(x + 1);
	}
	else
	{
		choose[x] = true;
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	int n,stick[5010]; 
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> stick[i];
	}
	
	int sum = 0, maxx = -1, num = 0;
	bool all_1 = true;
	
	next(1);
	
	int time = 0;
	
	for (int j = 1; j <= (1 << (n + 1)) - 1; j++)
	{
		sum = 0; maxx = -1;
		for (int i = 1; i <= n; i++)
		{
			if (choose[i])
			{
				sum += stick[i];
				
				//cout << stick[i] << " ";
				
				if (stick[i] > maxx)
				{
					maxx = stick[i];
				}
			}
		}
		
		//cout << maxx << " " << sum;
		if ((sum - maxx) > maxx)
		{
			num++;
			//cout << "AC";
		}

		next(1);
		//cout << endl
	}
	
	cout << num % 998244353;
	return 0;
} 
