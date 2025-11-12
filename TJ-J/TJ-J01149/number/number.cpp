#include<bits/stdc++.h>
using namespace std;
string s;
int vis[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' and s[i]<='9') vis[s[i]-48]++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=vis[i];j++) cout<<i;
	}
	return 0;
}
