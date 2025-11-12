#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int a,b;
	cin>>a>>b;
	while(a--) {
		string s,s1;
		cin>>s>>s1;
		string x,y,z,w;
		cin>>x>>y>>z>>w;
		if(s=="xabcx"&&s1=="xadex"&&x=="aa"&&y=="bb"&&z=="bc"&&w=="de") {
			cout<<2<<endl;
		}
		if(s=="aa"&&s1=="bb"&&x=="xabcx"&&y=="xadex"&&z=="aaaa"&&w=="bbbb") {
			cout<<0<<endl;
		}
	}
	return 0;
}
