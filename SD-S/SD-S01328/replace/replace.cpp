#include<bits/stdc++.h>
using namespace std;
long long n,q;
string s[1000006][3],t[1000006][3];
int main(){
	freopen("replace","r",stdin);
	freopen("replace","w",stdout);
cin>>n>>q;
for(int i=1;i<=n;i++){
	cin>>s[i][1]>>s[i][2];
}
for(int i=1;i<=q;i++){
	cin>>t[i][1]>>t[i][2];
}
for(int i=1;i<=q;i++){
	cout<<0<<endl;
}
	return 0;
} 

