#include<bits/stdc++.h>
using namespace std;

int main () {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	map<int,string>m1;
	map<int,string>m2;
	for(int i=1;i<=n;i++){
		cin>>m1[i]>>m2[i];
	}
	string s1,s2;
	for(int i=1;i<=q;i++){
		cin>>s1>>s2;
		cout<<n/2+i/2;
	} 
	return 0;
}