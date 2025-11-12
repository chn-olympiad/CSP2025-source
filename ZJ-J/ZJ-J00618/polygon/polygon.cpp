#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],ans=0,b[5010],c,d[5010],maxb,ansb;
void dfs(int kk)
{
	if(kk>n)
		return;
	for(int i=1;i<=n-kk+1;i++)
	{
		c=0;
		b[i]=1;
		d[c]=a[i];
		c++;
		for(int j=i;j<=n;j++)
		{
			if(b[j]==1)
				continue;
			if(kk-c!=1)
			{
				b[j]=1;
				d[c]=a[j];
				c++;
			}
			else
			{
				for(int jj=j+1;jj<=n;jj++)
				{
					ansb=0;
					maxb=0;
					for(int ii=0;i<c-1;i++)
					{
						if(d[ii]>maxb)
							maxb=d[ii];
						ansb+=d[ii];
					}
					if(ansb+a[jj]>maxb*2)
					{
						ans=(ans+1)%998244353;
						cout<<i<<j<<jj<<endl<<d[0]<<d[1]<<a[jj]<<endl<<ansb<<maxb<<endl;
						for(int q=0;q<=n;q++)
						{
							b[i]=0;
						}
					}
				}
			}
		}
	}
	dfs(kk+1);
}
int main()
{
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(3);
	cout<<ans;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
