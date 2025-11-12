#include<bits/stdc++.h>
using namespace std;
int a[500001],n,k,x[500001],c;
int find(int xx,int j)
{
	for(int i=j;i<=n;i++)
	{
		if(x[i]==xx&&i!=j&&i!=xx) return i;
	}
	return -1;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		x[i]=a[i]^x[i-1];
	}
	if(k==0){
    cout<<n/2;
	return 0;	
	}
	for(int i=1;i<=n;)
	{
		if(x[i]==k) c++;
		int p=find(k^x[i],i);
		if(p==-1)
		{
			i++;
		}
		else
		{
			c++;
			i=p;
		}
	}
	cout<<c;
	return 0;
}