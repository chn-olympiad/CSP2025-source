#include<bits/stdc++.h>
using namespace std;
#define int long long
int n[10];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			n[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(n[i]!=0){
			cout<<i;
			n[i]--;
		}
	}
	return 0;
}
