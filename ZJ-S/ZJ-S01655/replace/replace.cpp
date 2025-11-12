#include<bits/stdc++.h>
using namespace std;
typedef pair<string,string> P;
const int maxn=5e6+5;
string s,t;
map<P,bool> vis;
int n,q,ans;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	while(n--)
	 {
	 	cin>>s>>t;
	 	vis[P{s,t}]=true;
	 }
	while(q--)
	 {
	 	ans=0;
	 	cin>>s>>t;
	 	int l=0,r=s.size()-1;
	 	while(l<s.size()&&s[l]==t[l]) l++;
	 	while(r>=l&&s[r]==t[r]) r--;
	 	if(l>r) l--;
	 	for(int i=0;i<=l;i++)
	 	for(int j=r;j<s.size();j++)
	 	 {
	 	 	string s1=s.substr(i,j-i+1);
	 	 	string t1=t.substr(i,j-i+1);
	 		ans+=vis[P{s1,t1}];
		  }
		cout<<ans<<"\n";
	 }
	return 0;
}