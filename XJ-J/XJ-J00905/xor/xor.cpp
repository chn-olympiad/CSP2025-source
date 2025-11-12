#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long int n,k,z=1e5,c=0,x=0;
	long long int arr[z];
	cin>>n>>k;
	cin>>arr[0];
	if(arr[0]==k)
		c++;
	int p=1;
	for(int a=1;a<n;a++)
	{
		cin>>arr[a];
		if(p==1)
			x+=arr[a-1]|arr[a];
		else
			p=1;
		if(arr[a]==k||x==k)
		{
			c++;
			x=0;
			p=0;
		}
	}
	cout<<c;
	return 0;
}
