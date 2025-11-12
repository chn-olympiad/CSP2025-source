#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5+5;
int maxx=-1;
int n;
int a[N],b[N],c[N];
bool vis[N];
void dfs(int x,string s,int u,int v,int w){
	if(u>(n/2) || v>(n/2) || w>(n/2)){
		return;
	}
	if(x==n){
		int ans = 0;
		for(int i = 1;i<=s.size();i++){
			if(s[i-1]=='A') ans+=a[i];
			if(s[i-1]=='B') ans+=b[i];
			if(s[i-1]=='C') ans+=c[i];
		}
		maxx=max(ans,maxx);
	}
	dfs(x+1,s+"A",u+1,v,w);
	dfs(x+1,s+"B",u,v+1,w);
	dfs(x+1,s+"C",u,v,w+1);
}
struct node{
	int id;
	int a;
	int b;
	int c;
};
node r[N];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >aa,bb,cc;
int check(int i){
	int q = max(r[i].a,max(r[i].b,r[i].c));
	if(q==r[i].a){
		aa.push({r[i].a,r[i].id});
		if(aa.size()>(n/2)){
			pair<int,int>t=aa.top();
			aa.pop();
			r[t.second].a=-1e9;
			check(t.second);
		}
	}
	else if(q==r[i].b){
		bb.push({r[i].b,r[i].id});
		if(bb.size()>(n/2)){
			pair<int,int>t=bb.top();
			bb.pop();
			r[t.second].b=-1e9;
			check(t.second);
		}
	}
	else if(q==r[i].c){
		cc.push({r[i].c,r[i].id});
		if(cc.size()>(n/2)){
			pair<int,int>t=cc.top();
			cc.pop();
			r[t.second].c=-1e9;
			check(t.second);
		}
	}

}
void solve(){
	bool bl1=1,bl2=1;
	maxx=-1;
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
		if(b[i]!=0) bl1=0;
		if(c[i]!=0) bl2=0;
	}
	if(n<=13) dfs(0,"",0,0,0);
	else if(bl1&&bl2){
		maxx=0;
		sort(a+1,a+1+n);
		for(int i = n;i>=n/2;i--){
			maxx+=a[i];
		}
	}
	else{
		for(int i = 1;i<=n;i++){
			r[i].a=a[i];
			r[i].b=b[i];
			r[i].c=c[i];
		}
		for(int i = 1;i<=n;i++){
			r[i].id=i;
		}
		for(int i = 1;i<=n;i++){
			check(i);
		}
		int ans = 0;
		while(aa.size()){
			pair<int,int>t=aa.top();
			aa.pop();
			ans+=t.first;
		}
		while(bb.size()){
			pair<int,int>t=bb.top();
			bb.pop();
			ans+=t.first;
		}
		while(cc.size()){
			pair<int,int>t=cc.top();
			cc.pop();
			ans+=t.first;
		}
		maxx=ans;
	}
	cout<<maxx<<"\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) solve();

	return 0;
}

