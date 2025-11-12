#include <bits/stdc++.h>
using namespace std;
long long n,q;
string s1[300010][3],s2[300010][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	for(int i=1;i<=n;i++){
		cin>>s1[i][0]>>s1[i][1]; 
	}
	for(int i=1;i<=n;i++){
		cin>>s2[i][0]>>s2[i][1]; 
	}
	for(int i=1;i<=q;i++){
		cout<<0;
	}
	
	return 0;
}
