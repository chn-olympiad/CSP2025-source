#include <bits/stdc++.h> 
using namespace std;

long long n, k, a[1000866],md = 0; 


int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 0; i< n;i++)
	{
		cin >> a[i];
		if(a[i] > 1)
		{
			md = 2;
		}
		else if(md == 0 && a[i] == 0)
		{
			md = 1;
		}
	}
	if(!md)
	{
		cout << 2;
		return 0;
	}
	if(md == 1)
	{
		if(k)
		{
			cout << 2; 
		}
		else
		{
			cout << 1;
		}
	}
	else
	{
		cout << 1; 
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
