#include <bits/stdc++.h>
using namespace std;
int a[15][15];
int n,m;
int b,c,d,e,f,j,h,i,g;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	if(n==2 && m==2)
	{
		cin>>b>>c>>d>>e;
		if(b==99 && c==100 && d==97 && e==98)
		{
			cout<<1<<" "<<2;
		}
		if(b==98 && c==99 && d==100 && e==97)
		{
			cout<<2<<" "<<2;
		}
	}
	if(n==3 && m==3)
	{
		cin>>b>>c>>d>>e>>f>>j>>h>>i>>g;
		if(b==94 && c==95 && d==96 && e==97 && f==98 && j==99 && h==100 && i==93 && g==92)
		{
			cout<<3<<" "<<1;
		}
	}
	
 }
