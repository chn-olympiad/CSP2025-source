#include <bits/stdc++.h>
using namespace std;
int n,q;
string s,t,x[200010],y[200010];
bool check(string a,string b){
	if(a.size()!=b.size())return 0;
	for(int i=0;i<a.size();i++){
		if(a.size()!=b.size())return 0;
	}
	return 1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
	}
	while(q--){
		cin>>s>>t;
		if(s.size()!=t.size()){
			cout<<0<<"\n";
			continue;
		}
		int ans=0,l=0,r=s.size()-1;
		for(int i=0;i<s.size();i++){
			if(s[i]==t[i])l++;
			else break;
		}
		for(int i=s.size()-1;i>=0;i--){
			if(s[i]==t[i])r--;
			else break;
		}
		//cout<<l<<" "<<r<<"\n";
		for(int i=0;i<l;i++){
			for(int j=s.size()-1;j>=r;j--){
				string a,b;
				for(int k=i+1;k<j;k++)a+=s[k];
				for(int k=i+1;k<j;k++)b+=t[k];
				//cout<<a<<" "<<b<<'\n';
				for(int k=1;k<=n;k++){
					if(check(a,x[k])&&check(y[k],b)){
						ans++;
						break;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}