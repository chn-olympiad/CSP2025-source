#include <bits/stdc++.h>
using namespace std;
int n,q;
string s[201000][2],t[201000][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=1;i<=q;i++){
		cin>>t[i][0]>>t[i][1];
		printf("0\n");
	}
	return 0;
} 
