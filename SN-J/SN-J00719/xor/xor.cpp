#include<bits/stdc++.h>
using namespace std;
int a[500010];
int vis[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int x=1;
	int cnt=0;
	while(true)
	{
		//i,j£ºÇø¼ä 
		for(int i=1;i<=n-x+1;i++)
		{
			int sum=0;
			//cout<<'('<<i<<','<<i+x-1<<')'<<endl;
			bool flag=true;
			for(int j=i;j<=i+x-1;j++)
			{
				if(vis[j]==1)
				{
					flag=false;
					break;
				}
				sum=sum^a[j];
			}
			if(sum==k&&flag==true)
			{
				cnt++;
				//cout<<1<<'('<<i<<','<<i+x-1<<')'<<endl;
				for(int j=i;j<=i+x-1;j++)
				{
					vis[j]=1;
				}
			} 
		}
		x++;
		if(x>n)
		{
			break;
		 } 
	}
	cout<<cnt;
	return 0;
}
