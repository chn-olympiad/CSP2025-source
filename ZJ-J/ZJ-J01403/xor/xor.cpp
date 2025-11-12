#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[501000],maxn;
stack<int>q;
vector<int>b[1110100];
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	int ans=0;
	for(int i=1; i<=n; i++) {
		ans^=a[i];
		b[ans].push_back(i);
	}
	ans=0;
	for(int i=1; i<=n; i++) {
		int sh=0;
		for(int j=0;j<b[k^ans].size();j++){
			if(b[k^ans][j]>=i){
				sh=b[k^ans][j];
				break;
			}
		}
		if(sh) {
			if(q.empty()||q.top()<i)maxn++,q.push(sh);
			else if(q.top()>sh)q.pop(),q.push(sh);
		}
		ans^=a[i];
	}
	cout<<maxn;
	return 0;
}
