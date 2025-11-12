#include<bits/stdc++.h>
using namespace std;
int n,m,ans,vis[1000];
vector<int> v;
vector<int> z;
string s;
string ss;
void dfs(int p){
	if(p==n){
		int cnt=0;
		for(int i=0;i<v.size();i++){
			if(s[i]=='0'||cnt>=v[i])cnt++;
		}
		if(n-cnt>=m)ans++;
	}
	for(int i=0;i<n;i++){
		if(vis[i])continue;
		v.push_back(z[i]);
		s.push_back(ss[i]);
		vis[i]=1;
		dfs(p+1);
		vis[i]=0;
		s.pop_back();
		v.pop_back();
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>ss;
	for(int i=0,a;i<n;i++){
		cin>>a;
		z.push_back(a);
	}
	dfs(0);
	cout<<ans;
	return 0;
}
