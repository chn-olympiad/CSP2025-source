#include<bits/stdc++.h>
using namespace std;
string t;
long long a,b,s,n,m,x,y;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	s=1;
	for(int i=2;i<=m*n;i++)
	{
		cin>>b;
		if(b>a) s++;	
	}
	y=s/n+1;
	s%=n;
	if(s==0) 
	{
		y--;
		if(y%2!=0)
		{
			cout<<y<<" "<<n;
		}
		else
		{
			cout<<y<<" "<<"1";
		}	
		return 0;			
	}
	if(y%2!=0)
	{
		cout<<y<<" "<<s;
	}
	else
	{
		cout<<y<<" "<<n-s+1;
	}	
	return 0;
}
/*
2 2
99 100 97 98
2 2
98 99 100 97
3 3
94 95 96 97 98 99 100 93 92
*/