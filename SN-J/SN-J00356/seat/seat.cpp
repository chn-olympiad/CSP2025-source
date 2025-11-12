//SN-J00356 张景轩 山阳县第三中学
#include<bits/stdc++.h>
#include<stdio>
using namespace std;
int main
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m, a[110];
	int f = n*m;
	int sr = a[1];
	cin >> n, m;
	for(int i; i <= f; i ++)
	{
		cin >> a[i];
	}
	for(int i = 0; i <= len(a); i ++)
	{
		for(int j = 0; j < len(a); j ++)
		{
			if(a[i] < a[j])
			{
				swap(a[i], a[j]);
			}
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
 }
 

