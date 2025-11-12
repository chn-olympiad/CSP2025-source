#include <bits/stdc++.h>
using namespace std;
	int n, m; 
int main()
{
	freopen("replace.in","r","stdin");
	freopen("replace.out","w","stdout");
	cin >> n >> m;
	int t = 1;
	int f = 0;
	int j, o;
	int s;
	for(int i = 0; i <= n; i++)
	{
		if(j > o)
		{
			s = t;
		}
		else
		{
			s = f;
		}
	}
	int c;
	cin >> c;
	if(c > n / 10)
	{
		n = n - 1;
	}
	else
	{
		cout << m - n;
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}	
