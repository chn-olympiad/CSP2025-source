#include<bits/stdc++.h>
using namespace std;
bool gz(int a,int b,int c)
{
	if(a>b && a>c)
	{
		if(a*2>a+b+c)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	if(b>a && b>c)
	{
		if(a*2>a+b+c)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	if(c>b && c>a)
	{
		if(a*2>a+b+c)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polyon.out","w",stdout);
	int a;
	int b[10001]={0};
	cin>>a;
	for(int i=0;i<a;i++)
	{
		cin>>b[i];
	}
	return 0;
 } 
