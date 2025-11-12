#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n,k,a[N],b[N],last,ans;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
//	for(int i=1;i<=n;i++) cout<<b[i]<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j>=last;j--)
		{
			if((b[i]^b[j-1])==k)
			{
				last=i+1;
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
