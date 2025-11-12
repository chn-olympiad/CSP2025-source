#include<bits/stdc++.h>
using namespace std;
const int N=5e5+4;
int n,k,a[N],h,ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k)ans++;
		if(a[i]==1)h++; 
	}
	if(h==n)
	{
		if(k==1)
		{
			cout<<n;
			return 0;
		}
		else
		{
			cout<<0;
			return 0;
		}
	}
	else if(h<n)
	{
		cout<<h;
		return 0;
	}
	cout<<ans+1;
	return 0;	
} 
