#include<bits/stdc++.h>
using namespace std;
#define int long long
int t[15];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') t[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(t[i]>0){
			cout<<i;
			t[i]--;
		}
	}
	return 0;
}
