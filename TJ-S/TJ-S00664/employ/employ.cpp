#include <bits/stdc++.h>
using namespace std;
int n,m,nai[510],nan2[510],mj[510][510],def[250010],ghj=0;
char nan1[510];
void abc(int a)
{
	for(int i = 0; i < n; i++)
	{
		if(a > 1)
		{
			def[ghj] += pow(10,a)*mj[i];
			abc(a-1);
		}
		else if(a == 1)
		{
			def[ghj] = mj[i];
			ghj++;
			return;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> nan1;
	for(int i = 0; i < n; i++)
	{
		cin >> nai[i];
		if(nan1[i] == '0') nan2[i] = 0;
		else if(nan1[i] = '1') nan2[i] = 1;
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			mj[i][j] = nai[j];
		}
	}
	abc(n);
	return 0;
}
