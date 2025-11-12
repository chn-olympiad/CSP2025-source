#include <iostream>
#include <cstdio>
using namespace std;
int a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int fa=1,fb=1;
	if(k!=0) fa=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]!=1) fa=0;
		if(a[i]!=1&&a[i]!=0) fb=0;
	}
	if(fa)
	{
		cout<<n/2;
		return 0;
	}
	if(fb)
	{
		if(k==0)
		{
			int cnt=0;
			for(int i=0;i<n-1;i++)
			{
				if(a[i]==a[i+1])
				{
					i+=1;
					cnt+=1;
				}
				else if(a[i]==1)
				{
					cnt+=1;
				}
			}
			if(a[n-1]==1) cnt+=1;
			cout<<cnt;
			return 0;
		}
		if(k==1)
		{
			int cnt=0;
			for(int i=0;i<n-1;i++)
			{
				if(a[i]!=a[i+1])
				{
					i+=1;
					cnt+=1;
				}
				else if(a[i]==1)
				{
					cnt+=1;
				}
			}
			if(a[n-1]==1) cnt+=1;
			cout<<cnt;
			return 0;
		}
	}
	else
	{
		int cnt=0;
		int bnt=0;
		for(int i=0;i<n;i++)
		{
			bnt=bnt^a[i];
			int l=0,dnt=bnt;
			if(bnt!=k)
			{
				for(int j=i+1;j<n;j++)
				{
					dnt=dnt^a[j];
					if(dnt==k)
					{
						l=1;
						i=j;
						bnt=k;
						j=n;
					}
				}	
			}
			if(bnt==k||l==0)
			{
				if(bnt==k) cnt+=1;
				bnt=0;
			}
		}
		cout<<cnt;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
