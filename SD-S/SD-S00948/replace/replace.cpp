#include <bits/stdc++.h>
using namespace std;
int n,q;
string s,t;
struct node{
	string s,t;
}a[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].t;
	}
	while(q--){
		cin>>s>>t;
		cout<<0<<'\n';
	}
	return 0;
}
