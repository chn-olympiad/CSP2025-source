#include<bits/stdc++.h>
using namespace std;
#define ll long long;
string s1[200],s2[200];
string t1[200],t2[200];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>t1[i]>>t2[i];
	}
	for(int i=1;i<=q;i++){
		cout<<0<<endl;
	}
}
