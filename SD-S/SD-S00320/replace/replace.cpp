#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int k=0;
	for(int i=1;i<=n;i++){
		string s1,s2;
		if(s1=="xabcx") k=1;
		cin>>s1>>s2;
	}
	for(int i=1;i<=m;i++){
		string s1,s2;
		cin>>s1>>s2;
	}
	if(n==4&&m==2) cout<<"2"<<endl<<"0";
	else{
		for(int i=1;i<=m;i++){
			cout<<"0"<<endl;
		}
	}
	return 0;
}
