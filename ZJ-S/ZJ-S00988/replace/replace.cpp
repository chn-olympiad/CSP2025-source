#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][5],tt,ttt;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i][1]>>s[i][2];
	while(q--){
		int ans=0;
		cin>>tt>>ttt;
		if(tt.size()!=ttt.size()){
			cout<<0<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			int x=tt.find(s[i][1]),y=ttt.find(s[i][2]);
			if(x!=-1&&y!=-1&&x==y){
				string ozs=tt.substr(0,x)+s[i][2]+tt.substr(s[i][2].size()+x,tt.size()-s[i][2].size()-x);
				if(ozs==ttt)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
