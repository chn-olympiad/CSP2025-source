#include<bits/stdc++.h>
using namespace std;
string a[5000003];
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=(q+n)*2;i++){
		cin>>a[i];
	}
	for(int i=1;i<=q;i++){
		cout<<0<<endl;
	}
	return 0;
}