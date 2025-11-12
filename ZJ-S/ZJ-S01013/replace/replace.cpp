#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string a[200005],b[200005],x,y;
int c[200005],z,zz;
bool f;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		for(int j=0;j<=a[i].length();j++)
		{
			c[i]=j;
			if(a[i][j]!=b[i][j]) break;
		}
	}
		
	for(int i=1;i<=q;i++)
	{
		ans=0;
		cin>>x>>y;
		for(int j=0;j<x.length();j++)
			if(x[j]!=y[j])
				zz=j;
		for(int j=0;j<x.length();j++)
		{
			z=j;
			if(x[j]!=y[j])
			{
				for(int k=1;k<=n;k++)
				{
					f=1;
					for(int l=0;l<a[k].length();l++)
					{
						if(l+z-c[k]<0){
							f=0;continue;
						}
						if(a[k][l]!=x[l+z-c[k]]){
							f=0;continue;
						}
					}
					for(int l=0;l<b[k].length();l++)
					{
						if(l+z-c[k]<0){
							f=0;continue;
						}
						if(b[k][l]!=y[l+z-c[k]]){
							f=0;continue;
						}
					}
					if((b[k].length()+z-c[k])<=zz){
						f=0;continue;
					}
					if(f)
						ans++;
				}
				break;
			}
		}
		cout<<ans<<endl;
	}
}
