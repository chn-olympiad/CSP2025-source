#include<bits/stdc++.h>
using namespace std;
int n;
int aee[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	cin>>n;
	int x=0
	for(int a=0;a<n;a++)
	{
		cin>>arr[a];
		if(arr[a]>x)
			x=arr[a];
	}
	if(n=3)
		if(arr[0]+arr[1]>arr[2]&&arr[2]+arr[1]>arr[0]&&arr[0]+arr[2]>arr[1])
			cout<<1;
	else if(x=1)
	{
		long long ans=0;
		for(long long a=3;a<=n;a++)
		{
			for(long long b=1;b<a;b++)
				ans+=b;
		}
		cout<<ans%998244353;
	}
	
	
	
	
	
	return 0;
} 
