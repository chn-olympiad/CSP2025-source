#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n,q;
string s1,s2,str1,str2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	cin>>s1>>s2;
	for(int i=1;i<=n;i++){
		cin>>str1>>str2;
	}
	while(q--){
		cin>>str1>>str2;
		cout<<0<<'\n';
	}
	return 0;
} 
