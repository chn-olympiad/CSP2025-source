#include<bits/stdc++.h>
using namespace std;
int n,Q,maxn;
long long ans;
string s,ss;
map<string,string> mp;
queue<string> q;
set<string> se;
string sr(string s,int l,int r){
	string ans = "";
	for(int i = l;i<l+r;i++){
		ans+=s[i];
	}
	return ans;
}
void bfs(string s,string ss){
	q.push(s);
	while(!q.empty()){
		string now = q.front();
		q.pop();
		for(int i = 0;i<now.size();i++){
			for(int j = 1;j<=now.size()-i-1;j++){
				string sub = sr(now,i,j);
				if(mp[sub]=="") continue;
				string next = sr(now,0,i-1)+mp[sub]+sr(now,i+j-1,now.size());
				if(se.count(next)) continue;
				if(next==ss){
					ans++;
					continue;
				}
				se.insert(next);
				q.push(next);
			}		
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>Q;
	for(int i = 1;i<=n;i++){
		string u,v;
		cin>>u>>v;
		mp[u]=v;
	}
	while(Q--){
		ans = 0;
		cin>>s>>ss;
		bfs(s,ss);
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}
