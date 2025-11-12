#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y)
{
	return x>y; 
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int zs=n*m;
	for(int i=1;i<=zs;i++)
		cin>>a[i];
	int ans=a[1],zx=1,zy=1;
	sort(a+1,a+zs+1,cmp);
	bool flag=true;
	for(int i=1;i<=zs;i++)
	{
		if(a[i]==ans)
		{
			cout<<zy<<" "<<zx; 
			return 0;
		}
		if(flag==1)
		{
			if(zx<n)
				zx++;
			else if(zx==n)
			{
				zy++;
				flag=false;
			}
		}
		else if(flag==0)
		{
			if(zx>1)
				zx--;
			else if(zx==1)
			{
				zy++;
				flag=true;
			}
		}
	}
	return 0;
}
