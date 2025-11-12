#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,num[N],sum,ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>num[i];
	for(int i=1;i<=n;i++)
	{
		sum^=num[i];
		if(sum==k)
			ans++,sum=0;
	}
	cout<<ans;
	return 0;
}
