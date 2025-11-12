#include<bits/stdc++.h>
using namespace std;
string s[200010][5];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		int ans=0;
		if((int)t1.size()!=(int)t2.size()){
			cout<<0<<'\n';
			continue;
		}
		int l=0,r=0;
		for(int i=0;i<(int)t1.size();i++){
			if(t1[i]!=t2[i]){
				l=i;break;
			}
		}
		for(int i=(int)t1.size()-1;i>=0;i--){
			if(t1[i]!=t2[i]){
				r=i;break;
			}
		}
		for(int i=1;i<=n;i++){
			bool flag=0;
			if(i>l+1)flag=1;
			if(i+s[i][1].size()-1<=r)flag=1;
			for(int j=0;j<(int)s[i][1].size();j++){
				if(t1[i+j-1]!=s[i][1][j]||t2[i+j-1]!=s[i][2][j]){
					flag=1;
					break;
				}
			}
			if(!flag)ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
