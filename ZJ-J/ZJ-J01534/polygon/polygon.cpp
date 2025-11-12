#include<bits/stdc++.h>
using namespace std;
//È«ÅÅÁĞ+ÅĞ¶Ï 
int check(int num_ls[],int num)
{
	if(num < 3) return 0;
	int mx = 1;
	int sum = 0;
	for(int i = 1;i <= num;i++)
	{
		if(ls[i] >= mx) mx = ls[i];
		sum += i;
	}
	if(sum > 2 * mx)
	{
		return 1;
	}
	return 0;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	return 0;
}
