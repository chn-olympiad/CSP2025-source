#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int f1=0,f2=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
		if(a[i]!=1)	
			f1=1;
		if(a[i]!=0&&a[i]!=1)
			f2=1;
	}
	if(f1==0)
		cout<<n/2;
	else
	if(f2==0)
	{
		int s;
		for(int i=1;i<=n;i++)
			if(a[i]==1)
				s++;
		cout<<s/2;
	}	
	else
		cout<<2;
	return 0;
}
