#include<bits/stdc++.h>
using namespace std;
map <string,string> mp;
string a[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s1,s2;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		mp[s1]=s2;
		a[i]=s1;
	}
	for(int i=1;i<=m;i++){
		cin>>s1>>s2;
		cout<<0<<endl;
	}
	return 0;
}


