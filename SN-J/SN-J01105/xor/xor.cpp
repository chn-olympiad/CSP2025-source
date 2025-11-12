#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n,m,ans,a[N],b[N];
map<int,int> mp;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
	{
		mp[b[i-1]]=1;
		if (mp[m^b[i]])
		{
			ans++;
			mp.clear();
		}
	}
	cout<<ans<<"\n";
}
