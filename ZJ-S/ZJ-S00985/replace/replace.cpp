#include<bits/stdc++.h>
#define int long long
using namespace std;
map<pair<string,string>,bool>mp;
int n,q;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s,t;
		cin>>s>>t;
		mp[make_pair(s,t)]=1;
	}
	while(q--){
		string s,t,now1,now2;
		int ans=0;
		cin>>s>>t;
		int len=s.size(),l=1,r=0;
		r=len;
		s=' '+s;
		t=' '+t;
		for(int i=1;i<=len;i++){
			if(s[i]!=t[i]){
				l=i;
				break;
			}
		}
		for(int i=len;i>=1;i--){
			if(s[i]!=t[i]){
				r=i;
				break;
			}
		}
		for(int i=1;i<=l;i++){
			now1="",now2="";
			for(int j=i;j<r;j++){
				now1+=s[j];
				now2+=t[j];
			}
			for(int j=r;j<=len;j++){
				now1+=s[j];
				now2+=t[j];
				//cout<<now1<<" "<<now2<<endl;
				if(mp[make_pair(now1,now2)])ans++;
			}
		}
		cout<<ans<<endl;
	}
}
