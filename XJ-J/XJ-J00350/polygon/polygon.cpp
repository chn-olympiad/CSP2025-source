#include<bits/stdc++.h>
using namespace std;
int a[5005];
int Max(int x,int y,int z)
{
	int s;
	s=x;
	if(y>s)
	{
		s=y;
	} 
	if(z>s)
	{
		s=z;
	}
	return s;
 } 
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int i,j,n,m;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
    if(n==3)
    {
    	if(a[1]+a[2]+a[3]>2*Max(a[1],a[2],a[3]))
    	{
    		cout<<1;
		}
	} 

	return 0;
 } 
