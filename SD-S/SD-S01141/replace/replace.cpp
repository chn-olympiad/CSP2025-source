#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	string a,b;
}pq[114514];
	pair<string,string> p[114514];
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1; i<=n; i++){
		cin>>pq[i].a>>pq[i].b;
	}
	sort(pq+1,pq+n+1,[](node a,node b){
		return a.a.size()<b.a.size();
	});
	for(int i=1; i<=n; i++){
		p[i]={pq[i].a,pq[i].b};
	}
	while(q--){
		string x,y;
		cin>>x>>y;
		int l=-1,r;
		if(x.size()!=y.size()){
			cout<<0<<"\n";
			continue;
		}
		for(int i=0;i<x.size();i++){
			if(x[i]!=y[i]){
				if(l==-1) l=i;
				r=i;
			}
		}
		int len=r-l+1,cnt=0;
		for(int i=1; i<=n; i++){
			if(p[i].first.size()>=len){
				for(int j=l; j>=0&&j+p[i].first.size()-1>=r;j--){
					if(x.substr(j,p[i].first.size())==p[i].first&&y.substr(j,p[i].first.size())==p[i].second){
						cnt++;
					}
				}
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}

