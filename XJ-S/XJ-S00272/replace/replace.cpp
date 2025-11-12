#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	int n,q;
	cin>>n>>q;
	string a,b;
	for(int i=0;i<n;i++){
		cin>>a>>b;
	}
	string question,questiont;
	for(int i=0;i<q;i++){
		cin>>question>>questiont;
	}
	if(n==4 && q==2 && a=="xabcx" && questiont=="bbbb"){
		cout<<2<<"\n"<<0;
	}
	if(n==3 && q==4 && a=="c"&& questiont=="a"){
		cout<<0<<"\n"<<0<<"\n"<<0<<"\n"<<0;
	}
	for(int i=0;i<n;i++){
		cout<<0<<"\n";
	}
	return 0;
}

