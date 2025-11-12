#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,arr[100005],l=1,r=1,sum,ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)	cin>>arr[i];
	while(l<=n)
	{
		sum=0;
		for(int i=l;i<=r;i++)	sum^=arr[i];
		if(sum==k)  ans++;
		r++;
		if(r>n)	l++,r=l;
	}
	cout<<ans;
	return 0;
}