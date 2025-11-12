#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[500005],s[500005],ans;
struct node{
	int l,r;
	bool operator<(const node&o)const{return r<o.r;}
};
unordered_map<ll,int> mp;
vector<node> v;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i = 1;i<=n;i++) cin>>a[i],s[i]=s[i-1]^a[i];
	for(int i = 0;i<=n;i++){
		if(mp.find(s[i])!=mp.end())
			v.push_back({mp[s[i]]+1,i});
		if(a[i]==k) v.push_back({i,i});
		mp[s[i]^k] = i;
	}
	sort(v.begin(),v.end());
	int lst = 0;
	for(auto i:v)
		if(i.l>lst) ans++,lst = i.r;
	cout<<ans;
	return 0;
}
