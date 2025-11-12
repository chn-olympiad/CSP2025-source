#include<bits/stdc++.h>
#define int long long
using namespace std;
unordered_set<int> st;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int x;
	int pre=0,ans=0;
	st.insert(0);
	for(int i=1;i<=n;i++){
		cin>>x;
		pre^=x;
		if(st.find(pre^k)!=st.end()){
			ans++;
			st.clear();
			st.insert(0);
			pre=0;
			continue;
		}
		st.insert(pre);
	}
	cout<<ans<<endl;
	return 0;
}
