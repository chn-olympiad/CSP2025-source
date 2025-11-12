#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,q;
struct node{
	string x,y;
	bool operator<(const node &o)const{return x<o.x;}
}a[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i = 1;i<=n;i++) cin>>a[i].x>>a[i].y;
	sort(a+1,a+n+1);
	while(q--){
		string x,y;
		cin>>x>>y;
		int ans = 0,L=1e9,R=0;
		if(x.size()!=y.size()){
			cout<<0<<'\n';
			continue;
		}
		for(int i = 0;i<x.size();i++)
			if(x[i]!=y[i]) L = min(L,i),R = max(R,i);
		for(int l = 0;l<x.size();l++) for(int len = 1;l+len<=x.size();len++){
			if(l>L||l+len-1<R) continue;
			string t = x.substr(l,len);
			auto it = lower_bound(a+1,a+n+1,(node){t,""});
			if(it!=a+n+1&&(*it).x==t&&(*it).y==y.substr(l,len)) ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
