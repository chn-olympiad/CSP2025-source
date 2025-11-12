#include<bits/stdc++.h>
using namespace std;
int i,j,n,r,m,a[1006],s,v,t=0,flag;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    s=n*m;
	for(i=1;i<=s;i++)
	{
		cin>>a[i];
	}
	v=a[1];
	sort(a+1,a+1+s,greater<int>());
	for(i=1;i<=m;i++)
	{
		
	 for(j=1;j<=n;j++)
	 {
		t++;
		if(a[t]==v)
		{
			cout<<i<<" "<<j;
			return 0;
		}
		
	 }
	 	if(j==n)
		{
			for(i=1;i<=n;i++)
			for(j=n;j>=1;j--)
			{
				t++;
				if(a[t]==v)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	
	return 0;
} 
