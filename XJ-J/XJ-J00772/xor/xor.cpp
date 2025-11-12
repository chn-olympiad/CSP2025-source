#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,flag = 1;
	cin>>n>>k;
	vector<int> a(n+10);
	int id[200005][100];
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		if(a[i] != 1&& a[i] != 0)
			flag = 0;
	}
	if(flag == 1)
	{
	
		int total = 0;
		for(int i = 1; i <= n ; i ++)
		{
			if(a[i] == 1)
				total ++;
		} 
		if(k == 1)
			cout<<total;
		else
			cout<<0;
	}/*	
	else
	{
		int op[100]={0},x = k,j = 0,op1[100][200005]={0},tle = 0;
		while(x != 0)
		{
			op[++j] = x % 2;
			x /= 2;
			tle ++;
		}
		for(int i = 1; i <= n; i++)
		{
			int  q = a[i];
			j = 0;
			while(q != 0)
			{
				id[i][++j] = q % 2;
				q /= 2;
			}
		}
		for(int i = 1; i <= tle + 1; i++)
		{
			for(int k = 1; k <= n ; k++)
			{
				op1[i][k] = op[i][k-1] + id[i][k];
			}
		}
		for(int i = 1; i <= tle; i++)
		{
			
		}
	}*/
	fclose(stdin);
	fclose(stdout);
	return 0;
}
