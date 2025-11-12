#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	// !!!!!!!!!!!!!!!!!!!!!!!!!!
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s;cin>>s;
	string num;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			num.push_back(s[i]);
		}
	}
	sort(num.begin(),num.end());
	reverse(num.begin(),num.end());
	if(num[0]=='0') cout<<'0'<<endl;
	else{
		cout<<num<<endl;
	}
	return 0;
}

