#include<bits/stdc++.h>
using namespace std;
string s;
int cnt[111];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt[s[i]-'0']++;
		}
	}
	for(int j=9;j>=0;j--){
		for(int i=1;i<=cnt[j];i++){
			cout<<j;
		}
	}
	return 0;
}
