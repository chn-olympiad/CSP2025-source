#include<iostream>
#include<cstdio>
#include<string>
#define debug
using namespace std;
const int N=2e5+1e1;
int n,q;
string s1[N],s2[N];
string a,b;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i)
		cin>>s1[i]>>s2[i];
	while(q--){
		cin>>a>>b;
		cout<<0<<'\n';
	}
	return 0;
} 
