#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int t[10];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			t[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<t[i];j++){
			cout<<i;
		}
	}
	cout<<"\n";
	return 0;
}