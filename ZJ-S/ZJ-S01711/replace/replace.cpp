#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
typedef long long ll;
int n,q;
vector<pair<string,string> >arr;
ll read() {
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)) {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)) {
		x=(x<<1)+(x<<3)+(ch&15);
		ch=getchar();
	}
	return x*f;
}
ll dfs(string s,string t,int dep){
	if(s==t) return 1;
	if(dep==100) return 0;
	ll res=0;
	for(int i=0;i<arr.size();i++){
		int pos=s.find(arr[i].first);
		if(pos!=-1){
			string s1=s;
			for(int i=pos;i<pos+arr[i].second.size();i++){
				s[i]=arr[i].second[i-pos];
			}
			res+=dfs(s,t,dep+1);
			s=s1;
		}
	}
	return res;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	n=read(),q=read();
	
	for(int i=1;i<=n;i++){
		string x,y;
		cin>>x>>y;
		arr.push_back({x,y});
	}
	
	while(q--){
		string u,v;
		cin>>u>>v;
		cout<<dfs(u,v,0)<<'\n';
	}
	
	return 0;
}