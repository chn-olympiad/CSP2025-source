#include<bits/stdc++.h>
#define int long long
#define inf 500005
using namespace std;
int n,k;
int a[inf];
int linjie=0;
int p;
int ans;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		p=0;
		for(int j=i;j>linjie;j--)
		{
			p=(a[j] xor p);
		//	cout<<"i="<<i<<",j="<<j<<",p="<<p<<"\n";
			if(p==k)
			{
				linjie=i;
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
