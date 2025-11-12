#include<bits/stdc++.h>
using namespace std;
long long a[5000005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	long long cnt=0;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0)
		{
			cnt++;
		}
	}
	cout<<n-cnt;
}
