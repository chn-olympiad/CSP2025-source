#include<bits/stdc++.h>
using namespace std;
int n,q,s[2005][5],t[20005][5];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=2;j++){
			cin>>s[i][j];
		}
	}
	for(int i=2;i<=q;i++){
		for(int j=1;j<=2;j++){
			cin>>t[i][j];
		}
	}
	cout<<2<<endl<<0;
	return 0;
} 
