#include<bits/stdc++.h>
using namespace std;
//int dp[100010][4];
map<string ,string>mp;
struct ikun{
	int l=-1,r=-1;
}c[200010];
bool cmp(ikun a,ikun b){
	return a.l<b.l;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	int n,q;
	cin>>n>>q;
	string s[200010];

	bool flag=1;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		for(int j=0;j<s1.size();j++){
			if(s1[j]=='b')c[i].l=j+1;
			if(s2[j]=='b')c[i].r=j+1;
		}
		s[i]=s1;
		mp[s1]=s2;
	}
	//sort(c+1,c+n+1,cmp);
	//for(int i=1;i<=n;i++)cout<<c[i].l<<' '<<c[i].r<<'\n';
	if(c[1].l!=-1){
		int ans;
		while(q--){
			ans=0;
			string t1,t2;
			cin>>t1>>t2;
			int lt,rt;
			for(int j=0;j<t1.size();j++){
				if(t1[j]=='b')lt=j+1;
				if(t2[j]=='b')rt=j+1;
			}
			for(int i=1;i<=n;i++){
				if(c[i].l>lt||t1.size()-lt<s[i].size()-c[i].l)continue;
				if(rt==(lt-c[i].l)+c[i].r)ans++;
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<t1.size();j++){
				if(s[i]==t1.substr(j,s[i].size())){
					string t=t1;
					for(int k=j;k<j+s[i].size();k++){
						t[k]=mp[s[i]][k-j];
					}
					if(t==t2){
						ans++;
						break;
					}
					else{
						break;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
