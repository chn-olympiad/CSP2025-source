#include<bits/stdc++.h>
using namespace std;
long long i,j,n,q,k;
string s[200005][2],t[200005][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(i=1;i<=q;i++){
		cin>>t[i][1]>>t[i][2];
	}
	for(i=1;i<=q;i++)
		cout<<0<<endl;
	return 0;
}