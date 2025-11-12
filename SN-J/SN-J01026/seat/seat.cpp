#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105] ;
int s;
int main()
{
	//fropen(seat.in,"r",stdin);
	//fropen(seat.out,"w",stdout);
	cin >>n>>m;
	for(int i = 0;i < n*m;i++)
	{
		cin>> a[i] ;
	}
	s=a[0];
	sort(a+1,a+n*m+1) ;
	int x=1,y=1;
	for(int i =1;i <= n;i++)
	{
		for (int j = 1;j <= m;j++)
		{
			y++
		}
		x++;
	} 
	
}
