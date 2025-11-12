#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int b[1000001];
int biao[100000001];
int lr[10000001][2];
int bi(int n)
{
	int num=0,c=0;
	while(n!=0)
	{
		num=num+pow(10,c)*(n%2);
		n/=2;
		c++;
	}
	return num;
}
int shi(int n)
{
	int num=0,c=0;
	while(n!=0)
	{
		num+=(n%10)*pow(2,c);
		c++;
		n/=10;
	}
	return num;
}
int fun(int l,int r)
{
	if(l==r)return a[l];
	int x=b[l],y;
	for(int i=l+1;i<=r;i++)
	{
		y=b[i];
		int num=0,c=0;
		while(x!=0||y!=0)
		{
			if(x%10!=y%10)num+=pow(10,c)*1;
			c++;
			x/=10;
			y/=10;
		}
		x=num;
	}
	return shi(x);
}
int jud(int l,int r)
{
	for(int i=l;i<=r;i++)
	{
		if(biao[i])return 0;
	}
	return 1;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,sum=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=bi(a[i]);
	}
	int lri=1,lrcmax=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(k==fun(i,j))
			{
				lr[lri][0]=i;
				lr[lri][1]=j;
				if(j-i>lrcmax)lrcmax=j-i;
				lri++;
			}
		}
	}
	int lrc=0;
	for(lrc=0;lrc<=lrcmax;lrc++)
	{
		for(int i=1;i<lri;i++)
		{
			if(lr[i][1]-lr[i][0]==lrc)
			{
				if(jud(lr[i][0],lr[i][1]))
				{
					biao[lr[i][0]]=1;
					sum++;
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
//这是我的第一次CSP，有点紧张的
//后两题根本不会，服了，随便做一点能过几个样例就行了 
//话说有没有人会看啊 
