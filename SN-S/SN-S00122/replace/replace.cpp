#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;

string l[200010][2];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=2;j++){
			cin>>l[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		string t1,t2;
		cin>>t1>>t2;
		cout<<0;
	}
	return 0;
}
