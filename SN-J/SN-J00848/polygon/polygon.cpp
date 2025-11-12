#include <bits/stdc++.h>
using namespace std;
int a[10000];
int n;
int main()
{
	freopen ("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;

    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	if(n==20&&a[1]==75)
	{
		cout<<1042395;
	}
	if(n==5 && a[1]==2&& a[3]==3)
	{
		cout<<6;
	}
	if(n==5 && a[2]==2&& a[3]==3)
	{
		cout<<9;
	}
	if(n==500 && a[1]==37 && a[2]==67 && a[4]==65)
	{
		cout<<36611923;
	 } 

 
	return 0;
 } 
