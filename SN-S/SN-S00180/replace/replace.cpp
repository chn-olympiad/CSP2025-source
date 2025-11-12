#include<bits/stdc++.h>
using namespace std;
int cha[200005],l[200005],r[200005];
int find(string s){
	for(int i=0;i<s.size();i++){
		if(s[i]=='b'){
			return i;
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s,s2;cin>>s>>s2;
		int f=find(s),f2=find(s2);
		cha[i]=f2-f;
		l[i]=f;r[i]=s.size()-1-l[i];
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<endl;
			continue;
		}
		int x=find(t2)-find(t1);
		int ans=0;
		for(int i=1;i<=n;i++) {
			if(cha[i]==x&&find(t1)>=l[i]&&(t1.size()-1-find(t1))>=r[i]) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
