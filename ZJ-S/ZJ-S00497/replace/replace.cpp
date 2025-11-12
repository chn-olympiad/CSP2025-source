#include <bits/stdc++.h>
using namespace std;
string p,str[200005][2];
int n,q,st,ed;
string x,y;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	//LL!
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>str[i][0]>>str[i][1];
	}
	while(q--){
		cin>>x>>y;
		if(x.size()!=y.size()){
			cout<<0<<"\n";
			continue;
		}
		st=ed=-1;
		for(int i=0;i<x.size();i++)
			if(x[i]!=y[i]){
				if(st==-1) st=i;
				ed=i;
			}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(str[i][0].size()<ed-st+1) continue;
			int pos=0;
			while(x.find(str[i][0],pos)!=x.npos){
				pos=x.find(str[i][0],pos);
				p=x.substr(0,pos)+str[i][1]+x.substr(pos+str[i][0].size());
				if(p==y){
					ans++;
					break;
				}
				pos++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
