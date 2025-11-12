/*我们你所可以自慰的，想来想去，也还是所谓对于将来的希望。

希望是附丽于存在的，有存在，便有希望，有希望，便是光明。*/
#include<bits/stdc++.h>
using namespace std;
constexpr int N=505,p=998244353;
signed main(){
#ifdef __linux__
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
#endif
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,ans=1;cin>>n;
	for(int i=1;i<n;++i) ans=1ull*ans*i%p;
	cout<<ans<<'\n';
	return 0;
}
