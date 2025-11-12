#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
int n,q,ans,kq;
string s,s1;
map<string,pair<string,bool> > m;
map<string,bool> rf;
string k[50005];
void dfs(int l,int r){
	string ss,ts;
	for(int i=l;i<=r;i++){
		ss+=s[i];
		ts+=s1[i];
	}
	if(rf[ss])return;
	rf[ss]=1;
	k[++kq]=ss;
	if(m[ss].second&&ts==m[ss].first){
		ans++;
	}
//	cout<<ss<<" ";
	if(l>=0&&r+1<=s.size()-1){
		dfs(l,r+1);
	}
	if(r<=s.size()-1&&l-1>=0){
		dfs(l-1,r);
	}
	return;
	
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("relace.in","r",stdin);
	freopen("relace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		m[a].first=b;
		m[a].second=1;
	}
	while(q--){
		ans=0;
		cin>>s>>s1;
		int l=0,r=s.size()-1;
		for(;s[l]==s1[l]&&l<s.size();++l);
		for(;s[r]==s1[r]&&r>=0;--r);
		if(l>r){
			cout<<0<<endl;
			continue;
		}
		dfs(l,r);
		cout<<ans<<endl;
		for(int i=1;i<=kq;i++){
			rf[k[i]]=0;
		}
		kq=0;
	}
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
