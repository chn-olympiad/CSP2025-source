//SN-S00218  zhangjiakang  xi'an gaoxindiyizhongxue
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=505;
const int mod=998244353;
ll n,m;
string s;
ll a[maxn],b[maxn];
map<int,int> mp;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mp[a[i]]++;
	}
	sort(a+1,a+n+1);
	ll ans=0;
	do{
		ll tot=0,cnt=0;
		for(int i=1;i<=n;i++)
		{
//			cout<<a[i]<<" ";
			if(s[i-1]-'0'==0)
			{
				cnt++;
				continue;
			}
			if(cnt>=a[i])
			{
				cnt++;
				continue;
			}
			tot++;
			if(tot>=m)
			{
				ans++;
				ans%=mod;
				break;
			}
		}
//		cout<<endl;
	}while(next_permutation(a+1,a+n+1));
	for(auto v:mp)
		if(v.second>1)
			ans=ans*v.second%mod;
	cout<<ans;
	return 0;
}
