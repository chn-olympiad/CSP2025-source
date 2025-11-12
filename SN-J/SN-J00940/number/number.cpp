//SN-J00940 ΩØ”ÍÍÿ 
#include<bits/stdc++.h>
#define ll long long 
using namespace std;
string s;
vector<ll> q;
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("number.in","r",stdin); freopen("number.out","w",stdout);
	cin>>s; ll n=s.size();
	for(int i=0;i<n;i++) if(s[i]>='0'&&s[i]<='9') q.push_back(s[i]-'0');
	sort(q.begin(),q.end(),greater<ll>());
	if(q[0]==0) cout<<0;
	else for(auto i:q) cout<<i;
	return 0;
}
