#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int f[maxn],n,x,nw,k,ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		f[i]=f[i-1]^x;
	}
	for(register int i=1;i<=n;i++)
	{
		for(register int j=i;j>nw;j--)
		{
			int num=f[i]^f[j-1];
			if(num==k)
			{
				nw=i;
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}