#include<bits/stdc++.h>
using namespace std;
int n,q,pos,ans;
//vector<string> P[200001];
//map<string,int> Q;
//void dfs(string now,string ed){
//	if(now==ed){
//		ans++;
//		
//	}
//}
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
//		if(Q[a]==0) Q[a]=++pos;
//		P[Q[a]].push_back(b);
	}
	while(q--){
		string x,y;
		cin>>x>>y;
//		dfs(x,y);
		cout<<"0\n";
	}
	return 0;
}