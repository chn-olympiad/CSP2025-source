//T3
#include<iostream>
#include<cstdio>
#include<string>
#include<map>
using namespace std;
const int N=2e5+5;
pair<string,string> p[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string x,y;
		cin>>x>>y;
		p[i]={x,y};
	}
	while(q--){
		string x,y;
		cin>>x>>y;
		int ans=0;
		for(int len=1;len<=x.size();len++)
			for(int l=0,r=l+len-1;r<x.size();l++,r++){
				string t=x.substr(l,len);
				for(int pos=1;pos<=n;pos++){
					if(p[pos].first==t){
						if(x.substr(0,l)+p[pos].second+x.substr(r+1,x.size()-r-1)==y) ans++;
					}
				}
			}
		cout<<ans<<endl;
	}
	return 0;
}

