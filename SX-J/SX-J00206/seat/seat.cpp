#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int count = 0;
	int people[100];
	cin>>n>>m;
	for(int i = 0;i <= (n*m);i++)
	{
		cin>>people[0]>>people[i];
		if(people[0] < people[i]);
		{
			count++;
			i++;
		}
	}
	if(count != 0);
	{
		if(count < n || count < m)
		{
			count--;
		}

		if(count >= n);
		{
			int y = count/n;
			int t = count%n;
			if(y % 2 == 0 && t != 0);
			{
				if(count == (n*m))
				{
					cout<<n<<" "<<m;
					return 0;
				}
				else
				{
					if(count/n > 1 || count % n != 0)
					{count = count+(count/n+1);
						cout<<count/n+1<<" "<<m-t;
						return 0;
					}
					if(count/n == 1 &&count % n == 0)
					{

						cout<<count/n<<" "<<m-t;
						return 0;
					}

				}
			}
			if(count < n);
			{
				cout<<1<<" "<<count-1;
				return 0;
			}
			if(y % 2 == 1 && t != 0);
			{
				cout<<count/n<<" "<<t-1;
				return 0;
			}
			if(t == 0)
			{
				cout<<count/n<<" "<<m-1;
				return 0;
			}
		}

	}


	fclose(stdin);
	fclose(stdout);
	return 0;
}