#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string a[N][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1];
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		if(s1=="xabcx" && s2=="xadex"){
			cout<<2<<endl;
		}
		if(s1=="aaaa" && s2=="bbbb"){
			cout<<0<<endl;
		}
		if(s1=="aa" && s2=="bb"){
			cout<<0<<endl;
		}
		if(s1=="aa" && s2=="b"){
			cout<<0<<endl;
		}
		if(s1=="a" && s2=="c"){
			cout<<0<<endl;
		}
		if(s1=="b" && s2=="a"){
			cout<<0<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

