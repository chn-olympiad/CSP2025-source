#include<bits/stdc++.h>
#define int long long
#define rep(i,a,n) for(int i=a; i<=n; i++)
#define dop(i,a,n) for(int i=n; i>=a; i--)
#define Fast cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define fre(k) freopen(k".in","r",stdin),freopen(k".out","w",stdout)
using namespace std;
const int N=2e5+10;
int n,q;
string a,b;
unordered_map<string,int>mp;
signed main(){
	fre("replace");
	Fast;cin>>n>>q;
	rep(i,1,n){
		cin>>a>>b;
		if(a==b) continue;
		int l=0,r=a.size()-1;
		while(a[l]==b[l]) l++;
		while(a[r]==b[r]) r--;
		mp[a.substr(l,r-l+1)+"#"+b.substr(l,r-l+1)]++;
	}
	rep(i,1,q){
		cin>>a>>b;
		if(a.size()!=b.size()){cout<<"0\n";continue;}
		int l=0,r=a.size()-1;
		while(a[l]==b[l]) l++;
		while(a[r]==b[r]) r--;
		cout<<mp[a.substr(l,r-l+1)+"#"+b.substr(l,r-l+1)]<<"\n";
	}
	return 0;
}

