#include<bits/stdc++.h>
using namespace std;
int a[200010];
int n,k;
int check(int l,int r)
{
	int y=a[l];
	for(int i=l+1;i<=r;i++)
	{
		y^=a[i];
	}
	return y;
}
int fs(int l)
{
	int le=l,cnt=0;

	while(le<n)
	{
		for(int i=le;i<=n;i++)
		{
			if(check(le,i)==k)
			{
				return i;
			}
		}
		le++;
	}
	return 0;
 }
int dfs(int sc,int l)
{
	return 0;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	int cnt=0;
	bool l=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>1) l=0;
	 }
	 if(l)
	 {
	 	if(k==0)
	 	{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==0) cnt++;
				else if(a[i]==1 && a[i+1]==1)
				{
					cnt++;
					i++;
				}
			 } 
			 cout<<cnt;
			
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1) cnt++;
				
			 } 
			 cout<<cnt;
		}
	}
	return 0;
 }
