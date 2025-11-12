#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll N = 2e5 + 7;
string A[N],B[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ll n,q;
	scanf("%lld%lld",&n,&q);
	for (ll i = 1; i <= n; i ++) cin>>A[i]>>B[i];
	while (q --)
	{
		string x,y;
		cin>>x>>y;
		ll ans = 0;
		for (ll i = 0; i < x.size(); i ++)
		{
			for (ll j = 1; j <= n; j ++)
			{
				if (x[i] == A[j][0])
				{
					bool f = true;
					for (ll k = 0; k < A[j].size(); k ++) if (x[i + k] != A[j][k]) {f = false;break;}
					if (f)
					{
//					printf("%lld %lld\n",i,j);
						string t = x;
						t.erase(i,A[j].size());
//						cout<<t<<'\n';
						t.insert(i,B[j]);
//						cout<<t<<'\n';
						if (t == y) ans ++;
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
