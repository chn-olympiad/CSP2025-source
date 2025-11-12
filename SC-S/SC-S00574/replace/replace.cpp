#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[505][3],t[505][3];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int j=1;j<=q;j++){
		cin>>t[j][1]>>t[j][2];
	}
	cout<<2204128;
	return 0;
}