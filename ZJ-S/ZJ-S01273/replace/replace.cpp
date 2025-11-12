#include <bits/stdc++.h>
#define bug cout<<"114514";
using namespace std;
string s[5100000][3],t[5100000][3];
bool bl=0;
int aanswer;
bool qwq(string &s1,string &s2){
	if(s1.size()>s2.size()){
		return 0;
	}
	//bug
	for(int i=0;i<s2.size()-s1.size();++i){
		bl=0;
		for(int j=0;j<s1.size();++j){
			if(s1[j]!=s2[i+j])bl=1;
		}
		if(bl==0)return 1;
	}
	return 0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	//bug
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;++i){
		cin>>t[i][1]>>t[i][2];
		if(t[i][1].size()!=t[i][2].size()){
			cout<<"0\n";continue;
		}
		for(int j=1;j<=n;++j){
			if(qwq(s[j][1],t[i][1])&&qwq(s[j][2],t[i][2])){
				aanswer++;
			}
		}
		cout<<aanswer<<"\n";
		aanswer=0;
	}
}/*该说再见了qwq*/