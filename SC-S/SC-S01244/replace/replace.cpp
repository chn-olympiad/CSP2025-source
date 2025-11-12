#include<bits/stdc++.h>
#define ll long long
#define man 200005
using namespace std;
int n,q;
string s[man][3],x,y,cxk;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][1]>>s[i][2];
	while(q--){
		cin>>x>>y;int ans=0;
		if(x.size()!=y.size()){
			cout<<0<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<x.size();j++){
				if(x.size()-j<s[i][1].size()) break;
				int num=0,loc=j;
				for(int k=0;k<s[i][1].size();k++) if(s[i][1][k]==x[loc++]) num++;
				if(num!=s[i][1].size()) continue;
				num=0;loc=j;
				for(int k=0;k<s[i][2].size();k++) if(y[loc++]==s[i][2][k]) num++;
				if(num!=s[i][2].size()) continue;
				num=0;
				for(int k=0;k<j;k++) if(x[k]==y[k]) num++;
				if(num!=j) continue;
				num=0;
				for(int k=j+s[i][1].size();k<y.size();k++) if(x[k]!=y[k]) num++;
				if(num) continue;
				ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
rp++;
 3 4
 a b
 b c
 c d
 aa bb
 aa b
 a c
 b a

*/