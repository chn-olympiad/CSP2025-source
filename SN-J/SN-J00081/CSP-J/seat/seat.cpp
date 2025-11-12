#include<iostream>
#include<algorithm>
using namespace std;
int a[15][15];
int n,m,s;
void check(int x,int y)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(j%i==1)
			{
		       sort(a[i][j],a[n][j]);
		    }
		    if(j%i==0)
		    {
		    	sort(a[i][j],a[m][j]);
			}
		}
	}
	for(int i=1;i<=n*m;i++)
	     cout<<a[i];
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=m;j++)cin>>a[i][j];
    }
    check(n,m);
    return 0;
}
/*
x=a[0];
sort(a,a+s,cmp)
*/
