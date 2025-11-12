#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+10,maxV=1048580;
int n,k,s[maxn],mp[maxV];
signed main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1; i<=n; i++) cin>>s[i],s[i]^=s[i-1];
	int ans=0,last=0;
	for(int i=1; i<maxV; i++) mp[i]=-1;
	for(int i=1; i<=n; i++) {
		if(mp[s[i]^k]>=last) last=i,ans++;
		mp[s[i]]=i;
	}
	cout<<ans;
	return 0;
}