#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e2+5,P=998244353;
int n,m,c[N];
string s;
ll ans;
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	for (int i=1;i<=n;i++)
		cin>>c[i];
	ans=1LL;
	for (int i=1;i<=n;i++)
		ans=(ans*i)%P;
	printf("%lld\n",ans);
	return 0;
}
