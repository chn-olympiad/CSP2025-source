// SN-S00090  华紫陌   西安辅轮中学 
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m;
char s[501];
int c[501];
int cal(int x)
{
	int ans=1;
	for(int i=1;i<=x;i++) ans*=x;
	return ans;
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	cout<<cal(n);
	return 0;
}
