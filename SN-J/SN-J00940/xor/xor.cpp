//SN-J00940 ½¯ÓêêØ 
#include<bits/stdc++.h>
#define ll long long 
#define maxn 500005 
using namespace std;
ll n,k,a[maxn],ans;
set<ll> s;
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("xor.in","r",stdin); freopen("xor.out","w",stdout);
	cin>>n>>k; for(int i=1;i<=n;i++) cin>>a[i];
	ll num=0; s.insert(0);
	for(int i=1;i<=n;i++)
	{
		num^=a[i];
		if(s.count(num^k)) {s.clear(); ans++; num=0; s.insert(0);}
		else s.insert(num);
	}
	cout<<ans;
	return 0;
}
