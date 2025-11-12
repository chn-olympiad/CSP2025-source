#include<bits/stdc++.h>
using namespace std;
string s[10005][2],c,c1;
map<string,int>mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		mp[s[i][1]]++;
		mp[s[i][2]]++;
	}
	for(int i=1;i<=m;i++){
		cin>>c>>c1;
		cout<<mp[c1]<<endl;
	}
	return 0;
}
