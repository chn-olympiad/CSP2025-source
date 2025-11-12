#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define pb push_back
#define ls(x) x<<1
#define rs(x) x<<1|1
using namespace std;
vector<ll>ans;
string s;
inline bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>s;
	for(auto i:s){
		if(i>='0'&&i<='9') ans.pb(i-'0');
	}
	sort(ans.begin(),ans.end(),cmp);
	for(auto i:ans) cout<<i;
	return 0;
}

