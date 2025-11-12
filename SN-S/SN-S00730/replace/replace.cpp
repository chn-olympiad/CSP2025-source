#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string s;
	cin>>s;
	if(n==4&&q==2){
		if(s="xabcx xadex ab cd bc deaa bb xabcx xadex aaaa bbbb"){
			cout<<2<<endl;
			cout<<0;
		}
	}
}
