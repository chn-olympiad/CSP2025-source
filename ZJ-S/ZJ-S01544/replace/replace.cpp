#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	map<string,string> s1s2;
	for(int i=0;i<n;i++){
		string s1,s2;
		cin>>s1>>s2;
		s1s2[s1]=s2;
	}
	while(q--){
		string a,b;
		cin>>a>>b;
		if(a.size()!=b.size()){
			cout<<0<<endl;
			break;
		}
		int cnt=0;
		for(int i=0;i<a.size();i++){
			if(a[i]!=b[i]) break;
			for(int j=a.size()-1;j>=i;j++){
				if(a[j]!=b[j]) break;
				string s1=a.substr(i+1,j-i);
				string s2=b.substr(i+1,j-i);
				if(s1s2[s1]==s2){
					cnt++;
				}
			}
			string s1=a.substr(i+1,a.size()-i);
			string s2=b.substr(i+1,a.size()-i);
			if(s1s2[s1]==s2){
				cnt++;
			}
		}
			for(int j=a.size()-1;j>=0;j++){
				string s1=a.substr(0,j+1);
				string s2=b.substr(0,j+1);
				if(s1s2[s1]==s2){
					cnt++;
				}
			}
		cout<<cnt<<endl;
	}
	return 0;
}
