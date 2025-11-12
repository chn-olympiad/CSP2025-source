#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int n,m,sux[10011],mus;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	for(int i = 0;i < 10011; i ++)
	{
		sux[i] = -1;
	}
	cin >> n >> m;
	for(int i = 0;i < n;i ++)
	{
		cin >> sux[i];
	}
	if(m == 0)
	{
		for(int i = 0;i < n;i ++)
		{
			if(sux[i] == 0)
			{
				mus ++;
				continue;
			}
			if(sux[i] == 1 && sux[i + 1] == 1)
			{
				mus ++;
				i ++;
				continue;
			}
		}
		cout << mus;
	}	
	if(m == 1)
	{
		for(int i = 0;i < n;i ++)
		{
			if(sux[i] == 1)
			{
				mus ++;
				continue;
			}
			if(sux[i] == 0 && sux[i + 1] == 0)
			{
				mus ++;
				i ++;
				continue;
			}
		}
		cout << mus;
	}
	return 0;
}
