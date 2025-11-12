#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N=2e6+7,M=300,inf=1e18,mod=1e9+7;
int n,q,ans;
string s[N][5],goal;
bool check(string x){
	if(x.size()!=goal.size())return false;
	for(int i=0;i<x.size();i++){
		if(x[i]!=goal[i])return false;
	}
	return true;
}
void solve(string x){
	
	for(int i=1;i<=n;i++){
		string now=s[i][1],wil=s[i][2];
		int idx=x.find(now);
		if(idx>=x.size())continue;
		string new_x=x;
		new_x.replace(idx,now.size(),wil);
		if(check(new_x))ans++;
	}
	
}
signed main(){
//	string x="sfuhfag";
//	x.replace(2,1,"ede");
//	cout<<x;
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	while(q--){
		ans=0;
		string t1,t2;
		cin>>t1>>t2;
		goal=t2;
		solve(t1);
		cout<<ans<<"\n";
	}
	return 0;
} 
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/
