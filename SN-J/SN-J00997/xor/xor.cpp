#include<bits/stdc++.h>
using namespace std;
int n,k,sss,ret=0;
int a[500010],g[1001],he[1001]={0},dddd=0,ddd=0,dd,ans=0;
bool b[500010]={0};
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int flag=0;
			memset(he,0,sizeof(he));
			for(int k=i;k<=j;k++)
			{
				if(b[k]==1)
				{
					break;
				}
				sss=a[k];
				ret=0;
				memset(g,0,sizeof(g));
				while(sss>0)
				{
					g[++ret]=sss%2;
					sss/=2;
				}
				if(ret>ddd)
				{
					ddd=ret;
				}
				for(int dd=1;dd<=ddd;dd++)
				{
					if(he[dd]+g[dd]==1)
					{
						he[dd]=1;
					}
					else
					{
						he[dd]=0;
					}
				}
				flag=1;
			}
			if(flag==1)
			{
			
				ans=0;
				for(int i=1;i<=ddd;i++)
				{
					ans+=pow(2,i-1)*he[i];
				}
				if(ans==k)
				{
					dddd++;
					for(int k=i;k<=j;k++)
					{
						b[k]=1;
					}
				}	
			}
		}
	}
	cout<<dddd;
	return 0;
}
