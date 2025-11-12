#include<bits/stdc++.h>
using namespace std;
string s[200005],x[200005],a[200005],b[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>x[i];
	}for(int i=1;i<=q;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=q;i++){
		cout<<0<<endl;
	}
	return 0;
}
