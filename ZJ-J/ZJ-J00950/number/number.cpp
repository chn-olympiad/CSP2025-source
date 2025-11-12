#include <bits/stdc++.h>
using namespace std;
vector<signed> vt(10);
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	bool flag=false;
	for(signed i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			vt[s[i]-'0']++;
			flag=true;
		}
	}
	for(signed i=9;i>=0;i--){
		for(signed j=0;j<vt[i];j++){
			cout<<i;
		}
	}
	if(!flag) cout<<0;
	return 0;
}