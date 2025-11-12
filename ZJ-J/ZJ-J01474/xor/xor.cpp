#include<bits/stdc++.h>
using namespace std;
typedef unsigned int uint;
const int MAXN=5*1e5+10;
uint n,k;
uint cnt;
vector<uint> a(1);
vector<pair<uint,uint> > ans;
int main() {
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	a.resize(n+1);
	for(uint i=1; i<=n; i++) {
		cin>>a[i];
		a[i]^=a[i-1];
	}
	for(uint i=1; i<a.size(); i++) {
		for(uint j=i+1; j<a.size(); j++) {
			if((a[i]^a[j])==k) {
				ans.push_back(make_pair(j,i));
				break;
			}
		}
	}
	sort(ans.begin(),ans.end());
	uint cur=0;
	for(uint i=0; i<ans.size(); i++) {
		if(ans[i].second>=cur) {
			cnt++;
			cur=ans[i].first;
		}
	}
	cout<<cnt<<endl;
	return 0;
}