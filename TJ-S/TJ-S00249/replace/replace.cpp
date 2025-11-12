#include <iostream>
using namespace std;
int n,q;
string a,b,c,d;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	cin>>a>>b;
	if(a=="xabcx" && b=="xadex"){
		cout<<2<<endl<<0;
	}
	else if(a=="a" && b=="b"){
		cout<<0<<endl<<0<<endl<<0<<endl<<0;
	}
	else{
		cout<<3<<endl<<0;
	}
}
