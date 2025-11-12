#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans;
pair<int,int> c[502];
string a;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>a;
	for(int i=1;i<=n;i++) cin>>c[i].first,c[i].second=i;
	sort(c+1,c+1+n);
	do
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(c[i].first<=i-cnt-1) continue;
			cnt+=(a[i-1]=='1'); 
		}
		if(cnt>=m) ans=(ans+1)%998244353;
	}while(next_permutation(c+1,c+1+n));
	cout<<ans;
	return 0;
}
/*
依旧暴力
全排列枚举所有情况，统计答案即可。 
*/