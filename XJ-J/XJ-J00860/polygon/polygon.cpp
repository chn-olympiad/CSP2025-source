#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,n,a[5005],maxn=0,s=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>maxn)
		maxn=a[i];
		
		s+=a[i];
	}
	if(n==3&&s>2*maxn)
	cout<<1;
	else
	cout<<0;
	
	return 0; 
} 
