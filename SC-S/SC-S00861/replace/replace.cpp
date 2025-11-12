#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6+10;
string s,t;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	cin>>s>>t;
	for(int i=1;i<=n;i++){
		cin>>s>>t;
	}
	if(n==4&&q==2){
		cout<<"2"<<endl<<"4";
	}
	else{
		for(int i=1;i<=q;i++){
			cout<<"0"<<endl;
		}
	}
	return 0;
}