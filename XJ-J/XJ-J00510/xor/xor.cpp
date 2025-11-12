#include<bits/stdc++.h>
using namespace std;
long long int k,n,a[500005],b[105],c[105],t;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int r,l,i;
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		t+=a[i]; 
	}
	if(k==0)
	{
		cout<<n;
		return 0;
	}
	
	if(t==n&&k==0)
	{
		cout<<n<<endl;
	 	return 0;
	}
	if(t!=n&&k==0)
	{
		cout<<n-t<<endl;
		return 0;
	}
	
	return 0;
}
