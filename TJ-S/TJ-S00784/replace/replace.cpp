#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
map<string,string> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string x,y;
		cin>>x>>y;
		mp[x]=y;
	}
	while(q--){
		string s,t;
		cin>>s>>t;
		if (s.size()==1&&t.size()==1){
			if (mp[s]==t) {
				cout<<1<<endl;
				continue;
			}else{
				cout<<0<<endl;
				continue;
			}
		}
		ans=0;
		string x="",y="";
		for(int i=0;i<s.length();i++){
			if (i>=1) x+=s[i-1];
			for(int j=i;j<s.length();j++){
				string c="";
				for(int k=i;k<=j;k++){
					c+=s[k];
				}
				y="";
				for(int k=j+1;k<s.length();k++) y+=s[k];
				if (x+mp[c]+y==t) ans++;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
