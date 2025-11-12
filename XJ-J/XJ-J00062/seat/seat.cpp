#include <bits/stdc++.h>
using namespace std;
int m,n;
long long int cj[1100000];
long long int l=1,h=1;
int main()
{
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>cj[i];
	}
	for(int i=1;i<=n*m;i++)
	{
		if(l%2!=0)
		{
			if(cj[1]<=cj[i+1])
			{
				h+=1;
			}
			else
			{
				continue;
			}
			if(h>m)
			{
				l++;
				h=n;
			}	
		}
		else
		{
			if(cj[1]<=cj[i+1])
			{
				h-=1;
			}
			else
			{
				continue;
			}
			if(h<1)
			{
				l++;
				h=1;
			}
		}
	}
	cout<<l<<" "<<h;
	return 0;
}
