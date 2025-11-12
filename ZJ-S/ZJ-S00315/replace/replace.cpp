#include<bits/stdc++.h>
using namespace std;
int n,m;
map<string,string>m;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		string s,ss;
		cin>>s>>ss;
		m[s]=ss;
	}
	for(int i=1;i<=m;i++){
		string s1,s2;
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<0<endl;
		}
	}
}
