#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b)
{
	return a>b; 
}
int main()
{
	int n,m;
	cin>>n>>m;
	long long a[110],b[109];
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		b[i-1]=a[i];
	}
	int f=a[1];
	int k;
	sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
	    if(a[i]==f)
	    {
	    	k=i;
	    	break;
		}
	}
	int l,h;
	if(k%n==0)
	{
		l=k/n;
	}
	else
	{
		l=k/n+1;
	}
	h=n-k%n+1;
	if(l%2==1)
	{
		h=k%n;
		if(h==0)
		{
			h=n;
		}
	}
	cout<<l<<' '<<h;
	return 0;
} 
