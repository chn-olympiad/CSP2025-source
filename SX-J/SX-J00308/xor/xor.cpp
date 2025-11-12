#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5*1e5+5;
ll n,k,a[N],b[N];
unsigned ll sum=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(k==a[i])
		{
			sum++;
//			cout<<a[i]<<endl;
			b[i]++;
		}

	}
	for(int i=2;i<n;i++)
	{
		for(int j=1;j<=n-i;j++)
		{
			ll z=a[j];
			for(int kk=j;kk<=j+i;kk++)
				z^=a[kk];
			if(z==k)
			{
				sum++;
//				cout<<j<<" "<<j+i<<" "<<z<<endl;
			}

		}
	}
	cout<<sum;
	return 0;
}