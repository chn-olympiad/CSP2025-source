#include <bits/stdc++.h>
using namespace std;
int a[15][15];
int st[125];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int mul=n*m;
	int r;
	for (int i=1;i<=mul;i++)
	{
		cin>>st[i];
	}
	r=st[1];
	sort(st+1,st+mul+1,cmp);
	int cur=0;
	for (int j=1;j<=m;j++)
	{
		if(j%2==1)
		{
			for (int i=1;i<=n;i++)
			{
				cur++;
				
				if(st[cur]==r)
				{
					cout<<j<<" "<<i;
					return 0;
				}
				
			}	
		}
		else
		{
			for (int i=n;i>=1;i--)
			{
				cur++;
				
				if(st[cur]==r)
				{
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
	}		
	
	return 0;
 } 
