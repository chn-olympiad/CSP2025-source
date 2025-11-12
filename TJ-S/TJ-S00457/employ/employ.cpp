#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
const int p = 500;
using namespace std;
int n,m;
string str;
int c[p];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin >> n >> m;
	cin >> str;
	for(int i = 1;i <= n;i++)
	{
		cin >> c[i];
	}
	
	int hm = 0;
	for(int i = 1;i <= n;i++)
	{
		if(c[i] == 0 && str[i] == 1)
		{
			hm++;
			break;
		}
	} 
	
	
	return 0;
}
