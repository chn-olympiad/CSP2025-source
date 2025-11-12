#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r;
	cin>>n>>m;
	int ans[105] = {};
	for(int i = 0;i<n*m;i++)
	{
		cin>>ans[i];
	}
	r = ans[0];
	for(int i = 1;i<=n*m;i++)
	{
		int maxn = ans[i-1];
		int a = 0;
		for(int x = i;x<=n*m;x++)
		{
			if(ans[x]>maxn)
			{
				maxn = ans[x];
				a = ans[i-1];
				ans[i-1] = ans[x];
				ans[x] = a;
			}
		}
	}
	int num = 0;
	for(int i = 1;i<=n;i++)
	{
		
		if(i%2!=0)
		{
			for(int j = 1;j<=m;j++)
			{
				if(ans[num]>r)
				{
					num++;
				}
				else if(ans[num]<r)
				{
					break;
				}
				else if(ans[num] == r)
				{
					cout<<i<<" "<<j;
					num++;
					break;
				}
			}
		}
		else
		{
			for(int j = m;j>0;j--)
			{
				if(ans[num]>r)
				{
					num++;
				}
				else if(ans[num]<r)
				{
					break;
				}
				else if(ans[num] == r)
				{
					cout<<i<<" "<<j;
					num++;
					break;
				}
			}
		}
	}

	
	fclose("seat.in");
	fclose("seat.out");

	return 0;
} 

