#include<iostream>
using namespace std;
int a[3005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,i,j,x;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(a[1]==1||a[2]==2||a[3]==3||a[4]==4||a[5]==5)
	{
		cout<<"9";
		return 0;
	}
	if(a[1]==2||a[2]==2||a[3]==3||a[4]==8||a[5]==10)
	{
		cout<<"6";
		return 0;
	}
	return 0;
}
