#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int s[6][200010][4];
int fa[200010];
int nn[6];
int ans[6];
int z[4];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n;
		cin>>n;
		nn[i]=n;
		for(int j=1;j<=n;j++)
			{
				for(int k=1;k<=3;k++)
				{
					cin>>s[i][j][k];
				}
			}
	}
	for(int i=1;i<=t;i++)
	{
		int a=nn[i];
		for(int p=1;p<=a/2;p++) fa[p]=1;
		for(int p=a/2+1;p<=a;p++) fa[p]=2;
		fa[a]=1;
		z[1]=a/2+1;z[2]=a/2-1;z[3]=0;
		bool b=1;
		while(b)
		{
			int shu=0;
			while(1)
			{
				if(fa[a-shu]+1<=3)
				{
					z[fa[a-shu]]--;
					fa[a-shu]++;
					z[fa[a-shu]]++;
					break;
				}
				else
				{
					z[fa[a-shu]]--;
					fa[a-shu]=1;
					z[1]++;
				}
				shu++;
				if(shu==a) break;
			}
			if(z[3]==a) b=0;
			if(z[1]>a/2||z[2]>a/2||z[3]>a/2) continue;
			int jg=0;
			for(int j=1;j<=a;j++)
			{
				jg+=s[i][j][fa[j]];
			}
			ans[i]=max(ans[i],jg);
			if(z[3]==a-1&&z[2]==1) break;
		}
	}
	for(int i=1;i<=t;i++) cout<<ans[i]<<endl;
	return 0;
 }