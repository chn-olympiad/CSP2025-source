#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x > y;
}
int n,m,a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++)
		cin >> a[i];
	int pos = a[1];
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(pos == a[i])
		{
			pos = i;
		}
	}
	int sum=0;
	for(int i =1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
			    if(sum == pos)
			    {
				    cout << i << " " << j;
				}
				sum++; 
			}	
		}
	    if(i%2 == 0)
		{
			for(int j =n;j>=1;j--)
			{
				
			    if(sum == pos)
			    {
			    	cout << i << " " << j;
				}
				sum++;
			}
		}
	}
	
	return 0;
}

