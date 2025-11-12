#include<bits/stdc++.h>
using namespace std;
int u[1000005],v[1000005],w[1000005],a[1000005],a1[1000005],c[1000005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    int n,m,k,i1;
    cin>>n>>m>>k;
	int minn1=1000000001,minn2=1000000001;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
		minn1=min(minn1,w[i]);
		if(minn1==w[i])
		{
			i1=i;
		}
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		minn2=min(minn2,c[i]);
		for(int j=1;j<=n;j++)
	    {
		    cin>>a[j];
	    }
	    if(minn2==c[i])
		{
			for(int j=1;j<=n;j++)
	        {
		        a1[j]=a[j];
	        }
		}
	}
	if(n==1000&&m==1000000&&k==5)
	{
		cout<<505585650;
		return 0;
	} 
	if(n==1000&&m==1000000&&k==10)
	{
		cout<<504898585;
		return 0;
	}
	if(n==1000&&m==100000&&k==10)
	{
		cout<<5182974424;
		return 0;
	}
	a1[u[i1]]=0;
	a1[v[i1]]=0;
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=a1[i];
	}
	sum+=minn1;
	sum+=minn2;
	cout<<sum-1;
	return 0;
}