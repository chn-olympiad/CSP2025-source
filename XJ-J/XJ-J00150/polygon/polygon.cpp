#include <bits/stdc++.h>;
using namespace std;
int n,a[5010],s;
bool dbx(int x,int y)
{
	int w=0,max=0;
	for(int i=x;i<=y;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
		}
		w+=a[i];
	}
	if(w>max*2)
	{
		return true;
	}
	else
	{
		return false;
	} 
}
int main()
{
	freopen("polygon.in","r",stdin);
	cin>>n;
	for(int i=0;i<=n-1;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<=n-1;i++)
	{
		for(int j=i+2;j<=n-1;j++)
		{
			if(dbx(i,j))
			{
				s++;
			}
		}
	}
	freopen("polygon.out","w",stdout);
	cout<<s;
	return 0; 
}
