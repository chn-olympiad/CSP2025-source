#include<iostream>
#include<cmath>
using namespace std;
int a[500700],n,k;
int dfs(int l,int r,int val,int nd)
{
	int temp=nd;
	if(l==n+1||r==n+1)	return nd;
	if(l!=r)	val=val^a[r];
	for(int i=r;i<=n;i++)
	{
		if(val==k)
		{
			temp=max(temp,dfs(l+1,l+1,a[l+1],nd+1));
			break;
		}
		temp=max(temp,dfs(l,r+1,val,nd));
	}
	temp=max(temp,dfs(l+1,l+1,a[l+1],0));
	return temp;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);	
	}	
	cout<<dfs(1,1,a[1],0);
	return 0;
}
