#include<bits/stdc++.h>
using namespace std;
int a[5001];
long long n,sum,num;
void dfs(int r,int x)
{
	
	sum+=a[r];
	if(x==1)
	{
		if(sum>2*a[r])
		{
			num+=1;
		}
	}
	else
	{
		for(int i=r+1;i<=n-x+2;i++)
	{
		dfs(i,x-1);
	}
	}
	
	sum-=a[r];
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++)
	{
		dfs(0,i+1);
		
	}
	cout<<num;
	return 0;
	
 } 
