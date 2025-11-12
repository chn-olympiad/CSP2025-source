#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[2000005][3];
string t[2000005][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++){
		cin>>t[i][1]>>s[i][2];
	}
	return 0;
}
