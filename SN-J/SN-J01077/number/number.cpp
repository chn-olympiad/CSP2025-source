#include  <bits/stdc++.h>
using namespace std;
string s;
map<int,int>mp;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		int ans=(int)s[i];
		if(ans>=48 && ans<=57) mp[(ans-48)]++;
	}
	for(int i=9;i>=0;i--) for(int j=1;j<=mp[i];j++) cout<<i;
	return 0;
}
