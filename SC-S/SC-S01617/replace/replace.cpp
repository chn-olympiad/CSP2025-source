/*
xg333 CSP-S must win!!!
T3代码
xg333:加油！！！
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
map<string,string> mp;
string x[200001],y[200001];
string cut(int len,string s,int st){
	string ans="";
	for(int i=st;i<=st+len-1;i++){
		ans+=s[i];
	}
	return ans;
}
void solve(){
	int n,m;
	cin>>n>>m;
	string a,b;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		mp[a]=b;
		x[i]=a,y[i]=b;
	}
	for(int i=1;i<=n;i++){
		int len=x[i].size();
		for(int st=0;st<=n-len+1;st++){
			if(mp[cut(len,x[i],st)]!=""){
				string nx=cut(st,x[i],0)+mp[cut(len,x[i],st)]+cut(n-len-st,x[i],st+len);
				if(nx==y[i]){
					ans++;
				}
			}
			
		}
	}
	cout<<ans;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	t=1;
	while(t--){
		solve();
	}
	return 0;
}