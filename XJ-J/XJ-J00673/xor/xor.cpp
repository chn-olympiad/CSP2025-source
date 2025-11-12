#include<bits/stdc++.h>
using namespace std;
int n,k,f,l,r;
int a[500005];
int fun(int x,int y)
{
	int a2[40]={0},b2[40]={0},c2[40]={0};
	int k1=0,k2=0,i,ans=0;
	while(x!=0)
	{
		a2[++k1]=x%2;
		x/=2;
	}
	while(y!=0)
	{
		b2[++k2]=y%2;
		y/=2;
	}
	for(i=1;i<=max(k1,k2);i++)
	{
		if(a2[i]!=b2[i])
		 c2[i]=1;
		else
		 c2[i]=0;
	}
	for(i=1;i<=max(k1,k2);i++)
	 ans+=c2[i]*(int)pow(2,i-1);
	 
	return ans;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int i,j,ans=0,b=0,sum,s1;
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		f+=a[i];
		if(a[i]==k)
		 b++;
	}
	ans=b;
	if(k==0&&f==n)
	{
		while(n!=0)
		{
			ans+=n/2;
			n--;
		}
		cout<<ans;
		return 0;
	}
	else
	{
		for(l=1;l<n;l++)
		{
			for(r=l+1;r<=n;r++)
			{
				for(i=l;i<r;i++)
				{
					sum=a[i];
					s1=-1;
					for(j=i+1;j<=r;j++)
					 s1=fun(sum,a[j]);
					if(s1==k)
			 		 ans++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
