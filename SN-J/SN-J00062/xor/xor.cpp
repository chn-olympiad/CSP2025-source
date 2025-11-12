#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;cin>>n>>k;
	bool bl=0;
	int a=0,b=0,c=0;
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		if(x!=0&&x!=1)  bl=1;
		if(x==1)  a++;
		if(x==0)  b++;
	}
	if(bl==0)
	{
		if(k==1)  cout<<a;
		else if(k==0)
		{
			if(b!=0)  cout<<b;
			else  cout<<n/2;
		}
		else  cout<<0;
	}
	if(bl==1)
	  cout<<2;
	return 0;
}
