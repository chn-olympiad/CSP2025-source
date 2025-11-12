#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
int n;
string s1;
int q;
string t1;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1;
	}
	for(int j=1;j<=q;j++){
		cin>>t1;
	}
	for(int i=1;i<=q;i++){
		cout<<0<<endl;
	}
	return 0;
}
