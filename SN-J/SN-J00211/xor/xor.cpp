#include<bits/stdc++.h>
using namespace std;

const int maxn=5e5+15;
int n,k,ans,a[maxn];
set<int> s;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],a[i]^=a[i-1];
	s.insert(0);
	for(int i=1;i<=n;i++){
		if(s.count(a[i]^k)){
			++ans;
			s.clear();
		}
		s.insert(a[i]);
	}
	cout<<ans<<'\n';
	return 0;
}
