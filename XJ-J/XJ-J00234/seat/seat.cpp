#include <bits/stdc++.h>
using namespace std;

int n,m;
int c[105];

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>c[i];
	int co=c[1];
	sort(c+1,c+1+n*m);
	int z=1;
	for(int i=n*m;i>=1;i--)
	{
		if(c[i]!=co)z++;
		else break;
	}

	
	int zc=z/n;
	
	
	int zy=z%n;
	if(zy==0)
	{
		if(zc%2==0)cout<<zc<<" "<<1;
		else cout<<zc<<" "<<n;
	}
	else
	{
		if(zc%2==0)cout<<zc+1<<" "<<zy;
		else cout<<zc+1<<" "<<n-zy+1;
	}
	
	 
	return 0;	
} 
