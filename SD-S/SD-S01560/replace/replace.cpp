#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,q;
string s[3],s1[3];
int main(){
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s[i][1]>>s[i][2];
	}
	cout<<s[1][1]<<' '<<s[1][2]<<'\n';
	
	return 0;
}

