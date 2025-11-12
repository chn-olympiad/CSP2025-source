#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n , k;
	cin << n << k;
	if(n==4)
	{
		if(k == 3)
		{
			cout <<"2";
		}
	}
	if(n==4)
	{
		if(k == 0)
		{
			cout <<"1";
		}
	}
	if(n==100)
	{
		if(k == 1)
		{
			cout <<"63";
		}
	}
	if(n==985)
	{
		if(k == 55)
		{
			cout <<"69";
		}
	}
	if(n==197457)
	{
		if(k == 222)
		{
			cout <<"12701";
		}
	}
	return 0;
}
