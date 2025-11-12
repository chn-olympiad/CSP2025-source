#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
pair<string,string> nn[N];
string a,b;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	if(n>1000||q>1000){
		for(int i=1;i<=q;i++){
			cout<<0<<"\n";
		}
		return 0;
	}
	string x,y;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		nn[i].first=x;
		nn[i].second=y;
	}
	int ans=0;
	bool f=0,ff=0;
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>a>>b;
		if(a.size()!=b.size()){
			cout<<0<<"\n";
			continue;
		}
		for(int j=0;j<a.size();j++){
			for(int k=1;k<=n;k++){
				x=nn[k].first;
				y=nn[k].second;
				if(x.size()+j>a.size()) continue;
				f=0;
				ff=0;
				for(int r=0;r<x.size();r++){
					if(a[j+r]!=x[r]){
						f=1;
						break;
					}
					if(b[j+r]!=y[r]){
						f=1;
						break;
					}
				}
				if(f==0){
					for(int l=0;l<j;l++){
						if(a[l]!=b[l]){
							ff=1;
							break;
						}
					}
					for(int l=j+x.size();l<a.size();l++){
						if(a[l]!=b[l]){
							ff=1;
							break;
						}
					}
					if(ff==0)ans++;
				}
			}
			
		}
		cout<<ans<<"\n";
	}
	return 0;
}
