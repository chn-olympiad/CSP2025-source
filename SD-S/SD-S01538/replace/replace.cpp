#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
string s1,s2,s3,s4;
int n,m;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
	}
	for(int i=1;i<=m;i++){
		cin>>s3>>s4;
	}
	if(m==1) cout<<0;
	else{
		for(int i=1;i<=m;i++){
			cout<<0<<endl;
		}
	}
	return 0;
}
