#include<bits/stdc++.h>
using namespace std;

int n,q;
string t1,t2;
pair<string,string> s[200005];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s[i].first>>s[i].second;
	}
	while(q--){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<"0\n";
			continue;
		}
		int ans=0;
		for(int i=0;i<t1.size();++i){
			for(int j=t1.size()-1;j>=i;--j){
				string a=t1.substr(i,j-i+1);
				string b=t2.substr(i,j-i+1);
				for(int k=1;k<=n;++k){
					if(s[k].first==a&&s[k].second==b)++ans;
				}
				if(t1[j]!=t2[j])break;
			}
			if(t1[i]!=t2[i])break;
		}
		printf("%d\n",ans);
	}
	
	return 0;
}
