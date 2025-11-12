#include<bits/stdc++.h>
using namespace std;
#define int long long
int vis[15];
string s;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			vis[s[i]-'0']+=1;
		}
	}
	for(int i=9;i>=0;i--){
		while(vis[i]){
			cout<<i;
			vis[i]-=1;
		}
	}
	return 0;
}