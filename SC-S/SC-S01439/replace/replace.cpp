#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	map<string,string>mp;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		mp[s1]=s2;
	}while(q--){
		string s1,s2;
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<0<<'\n';
			continue;
		}int l=s1.size(),r=0,cnt=0;
		for(int i=0;i<=s1.size();i++){
			if(s1[i]!=s2[i]){
				l=min(l,i);
				r=i;
			}
		}for(int i=0;i<=l;i++){
			string t1,t2;
			for(int j=i;j<s1.size();j++){
				t1+=s1[j];
				t2+=s2[j];
				if(j>=r&&mp[t1]==t2)cnt++;
			}
		}cout<<cnt<<'\n';
	}
	return 0;
}