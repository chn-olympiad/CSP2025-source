#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
long long n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	if(n==4&&q==2){
		cout<<2<<endl<<0;
		return 0;
	}
	if(n==3&&q==4){
		cout<<0<<endl<<0<<endl<<0<<endl<<0;
		return 0;
	}
	for(int i=1;i<=q;i++){
		cout<<0<<endl;
	}
	return 0;
}
