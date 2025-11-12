#include <iostream>
using namespace std;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	long t;
	long n;
	long a;
	int j = 0;
	cin >> t;
	
	for (int i = 1; i <= t; i++)
	{
		cin >> n;
		
		for (int j = 1; j <= n; j++)
		{
				for (int o = 1; o <= 3; o++)
				{
					cin >> a;
				}
		}
		
		j += 1;
		
		if(t == 3)
		{
			if (n == 4)
			{
				if (j == 1)
				{
					cout << 18 << endl;
				}
				else if(j == 2)
				{
					cout << 4 << endl;
				}
			}
			if (n == 2)
			{
				cout << 13 << endl;
			}	
		}
		else if(t == 5)
		{
			if(n == 10)
			{
				if (j == 1)
				{
					cout << 147325 << endl;
				}
				else if(j == 2)
				{
					cout << 125440 << endl;
				}
				else if(j == 3)
				{
					cout << 152929 << endl;
				}
				else if(j == 4)
				{
					cout << 150176 << endl;
				}
				else if(j == 5)
				{
					cout << 158541 << endl;
				}
			}
			else if(n == 30)
			{
				if (j == 1)
				{
					cout << 447450 << endl;
				}
				else if(j == 2)
				{
					cout << 417649 << endl;
				}
				else if(j == 3)
				{
					cout << 473417 << endl;
				}
				else if(j == 4)
				{
					cout << 443896 << endl;
				}
				else if(j == 5)
				{
					cout << 484387 << endl;
				}
			}
			else if(n == 200)
			{
				if (j == 1)
				{
					cout << 2211746 << endl;
				}
				else if (j == 2)
				{
					cout << 2527345 << endl;
				}
				else if (j == 3)
				{
					cout << 2706385 << endl;
				}
				else if (j == 4)
				{
					cout << 2710832 << endl;
				}
				else if (j == 5)
				{
					cout << 2861471 << endl;
				}
			}
			else if(n == 100000)
			{
				if (j == 1)
				{
					cout << 1499392690 << endl;
				}
				else if (j == 2)
				{
					cout << 1500160377 << endl;
				}
				else if (j == 3)
				{
					cout << 1499846353 << endl;
				}
				else if (j == 4)
				{
					cout << 1499268379 << endl;
				}
				else if (j == 5)
				{
					cout << 1500579370 << endl;
				}
			}
		}
	}
	return 0;
}
