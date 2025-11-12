#include <bits/stdc++.h>
using namespace std;
string s;
int cnt[12],flag;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='1'){
			cnt[s[i]-'0']++;
			flag=1;
		}
		else if(s[i]=='0'){
			cnt[0]++;
		}
	}
	if(flag==1){
		for(int i=9;i>=0;i--){
			for(int j=1;j<=cnt[i];j++){
				cout<<i;
			}
		}
		return 0;
	}
	else cout<<0;
	return 0;
}
