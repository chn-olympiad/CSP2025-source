#include<bits/stdc++.h>
#define N 200002
using namespace std;
int n,q;
long long res;
map<pair<int,int>,int>cnt;
string s[N][2],s1,s2;
void solve(){
	res=0LL;
	cin>>s1>>s2;
	for(int i=1;i<=n;i++){
		int p=s1.find(s[i][0]);
		if(p==-1) continue;
		string x=s1.substr(0,p);
		string y=s[i][1];
		string z="";
		if(p+s[i][0].size()<s1.size())
			z=s1.substr(p+s[i][0].size());
		if(x+y+z==s2) res++;
	}
	cout<<res<<'\n';
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1];
	while(q--) solve();
	return 0;
}
