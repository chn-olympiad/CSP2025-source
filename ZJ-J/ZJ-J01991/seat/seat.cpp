#include<bits/stdc++.h>
using namespace std;
int n,m,x,st;
bool f[200];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>x;
			if(i==1&&j==1)
			{
				st=x;
			}
			f[x]=true;
		}
	}
	int it=100,l=1,r=0;
	while(it>=st)
	{
		if(f[it])
		{
			if(l%2==1)//ÆæÊý 
			{
				r++;
				if(r>m)
				{
					l++;
					r=m;
				}
			} 
			else
			{
				r--;
				if(r<1)
				{
					l++;
					r=1;
				}
			}
		}
		it--;
	}
	cout<<l<<" "<<r<<"\n";
	return 0;
}
