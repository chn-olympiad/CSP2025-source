#include<bits/stdc++.h>
using namespace std;
int read(){
	char c=getchar();
	int x=0,g=1;
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') g=-1,c=getchar();
	while(c>='0' && c<='9'){
		x=x*10+c-'0';c=getchar();
	}
	return x*g;
}
unordered_map<string,vector<string> > mp;
int n,q,ans;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();q=read();
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		mp[s1].push_back(s2);
	}
	while(q--){
		ans=0;
		string t1,t2;cin>>t1>>t2;
		int len=t1.size();
		if(len!=t2.length()){
			puts("0");continue;
		}
		for(int l=0;l<len;l++){
			if(l!=0 && t1[l-1]!=t2[l-1]) break;
			for(int r=len-1;r>=0;r--){
				if(r!=len && t1[r+1]!=t2[r+1]) break;
				string a1=t1.substr(0,l),a2=t1.substr(l,r-l+1),a3=t1.substr(r+1,len-r-1);
				if(mp.find(a2)!=mp.end()){
					for(auto y:mp[a2]){
						if(a1+y+a3==t2) ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
