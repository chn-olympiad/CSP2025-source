#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using db=double;
using pii=pair<int,int>;

#define endl '\n'

const long long modd=998244353;

ll solve(int n)
{
	ll ans=1;
	for(int i=2;i<=n;i++)
	{
		ans*=i;
		if(ans>=modd)
		{
			ans%=modd;
		}
	}
	return ans;
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	cout<<solve(n)<<endl;
	return 0;
}
