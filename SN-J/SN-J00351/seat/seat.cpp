#include<bits/stdc++.h>
using namespace std;
int main()
{
	int q[110][110];
	int k[110];
	int a,b;
	cin >> a >> b;
	for(int i = 1; i <= a*b; i++)
	{
		cin >> k[i];
	}
	sort(k+1,k+a*b+1);
	int v[110];
	int e = 1;
	for(int i = a*b; i >= 1; i--)
	{
		v[e] = k[i];
		e++;
	}
	int cnt = 1;
	for(int i = 1; i <= b; i++)
	{
		if(i%2 == 0)
		{
			for(int j = 1; j < a; j++)
			{
			

				q[i][j] = v[cnt];
				cout << q[i][j] << " ";
				cnt++;
			}
		}
		else
		{
			for(int j = a; j >= 1; j--)
			{
				q[i][j] = v[cnt];
				cout << q[i][j] << " ";
				cnt++;
			}
		}
		for(int i = 1; i <= a; i++)
		{
			for(int j = 1; j <= b; j++)
			{
				if(q[i][j] == v[1])
				{
					cout << i << " " << j;
					return 0;
				}
			}
		}
	}
	
	
	
	
	 
	return 0;
} 
 
