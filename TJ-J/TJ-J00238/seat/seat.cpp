#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout); 
	int m,n;
	cin>>n>>m;
	int x,y,b[n*m];
	y=n*m;
	for(int i=0;i<n*m;i++)
	{
		cin>>b[i];
	}
	x=b[0];
	sort(b,b+n*m+1);
	reverse(b,b+n*m+1);
	/*for(int i=0;i<n*m;i++)
	{
		cout<<b[i];
	}*/
	int i=0,j=1,k=0;
	for(int k=0;b[k]==x;k++)
	{
		if(j%2==0)i--;
		else i++;
		if(i>n)
		{
			i--;
			j++;
		}
		else if(i<0)
		{
			i=0;
			j++;
		}
		
	}
	cout<<j<<' '<<i;
}
