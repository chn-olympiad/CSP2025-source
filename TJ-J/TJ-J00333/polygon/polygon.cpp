#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a,b,s;
	int ans[5005] = {};
	cin>>a;
	for(int i = 0;i<a;i++)
	{
		cin>>ans[i];
	}
	for(int i = 1;i<=a;i++)
	{
		int maxn =0;
		for(int x = i;x<=a;x++)
		{
			if(ans[x]>maxn)
			{
				maxn = ans[x];
				s = ans[i-1];
				ans[i-1] = ans[x];
				ans[x] = s;
			}
		}
	}
	int num = 3;
	while(num<=a)
	{
		int maxn = -1,end = 0;
		for(int i = 0;i<a;i++)
		{
			end+=ans[i];
			if(ans[i]>maxn)
			{
				maxn = ans[i];
			}
		}
		if(end > maxn+maxn)
		{
			b++;
		}
		num++;
	}
	cout<<b;
	fclose("polygon.in");
	fclose("polygon.out");
	return 0;
} 

