#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005],t[200005],x,y;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>t[i];
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		cin>>x>>y;
		for(int i=1;i<=n;i++){
			int h=x.find(s[i]);
			string ss=x.substr(0,h);
			string sss=x.substr(h+s[i].size(),x.size()-(h+s[i].size()));
			string st=ss+t[i]+sss;
			if(st==y)ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}

