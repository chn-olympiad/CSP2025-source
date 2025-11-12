#include<bits/stdc++.h>
using namespace std;
int f[505][505],c[505];//tian_lu
bool r[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	int n,m,sum=0;
	cin>>n>>m;getchar();
	for(int i=1;i<=n;++i)
	{
		if(getchar()=='1')r[i]=true;
	}
	for(int i=1;i<=n;++i)cin>>c[i];
	f[0][0]=1;
	for(int i=1;i<=n;++i)//ren
	{	
		for(int j=n;j>=1;--j)
		{
			//qiahaolai
			int w=max(0,j-c[i]);
			if(r[i]==1)//kl
			{
				for(int k=0;k<w;k++)
				{
					f[j][k]=(f[j-1][k]+f[j][k])%998244353;
				}
				for(int k=w;k<=j-1;++k)
					f[j][k+1]=(f[j][k+1]+f[j-1][k])%998244353;
				
			}
				
			
			
			//bl
			if(r[i]==0)for(int k=0;k<=j-1;++k)f[j][k]=(f[j-1][k]+f[j][k])%998244353;
			
		}
	}
//	for(int i=0;i<=n;++i)
//	{
//		for(int j=0;j<=n;++j)cout<<f[i][j]<<" ";
//		cout<<endl;
//	}
	
	for(int i=m;i<=n;++i)
	{
		for(int j=m;j<=i;++j)
		{
			sum=(sum+f[i][j])%998244353;
		}
	}
	cout<<sum;
	fclose(stdin);fclose(stdout);
	return 0;
}
//998244353
