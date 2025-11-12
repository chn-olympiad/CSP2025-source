#include<bits/stdc++.h>
using namespace std;
int n,m;
string s,s1;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s;
	}
	for(int i=1;i<=m;i++){
		cin>>s;
		cout<<s.size()/2<<endl;
	}
	return 0;
}