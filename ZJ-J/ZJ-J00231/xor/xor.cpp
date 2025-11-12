#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll N=500010;
ll n,m,a[N],ans;
unordered_map<ll,bool> mp;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]^=a[i-1];
	}
	mp[0]=true;
	for(int i=1;i<=n;i++)
	{	
		if(mp[a[i]^m])
		{
			ans++;
			mp.clear();
		}
		mp[a[i]]=true;
	}
	cout<<ans<<"\n";
	return 0;
}