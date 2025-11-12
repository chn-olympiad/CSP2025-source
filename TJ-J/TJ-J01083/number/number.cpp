#include<bits/stdc++.h>
using namespace std;
string s,ans;
int cnt[15],num;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i] && s[i]<='9'){
			cnt[s[i]-'0']++;
			num++;
		}
	}
	char p='9';
	for(int i=1;i<=cnt[9];i++){
		ans+='9';
	}
	for(int i=1;i<=cnt[8];i++){
		ans+='8';
	}
	for(int i=1;i<=cnt[7];i++){
		ans+='7';
	}
	for(int i=1;i<=cnt[6];i++){
		ans+='6';
	}
	for(int i=1;i<=cnt[5];i++){
		ans+='5';
	}
	for(int i=1;i<=cnt[4];i++){
		ans+='4';
	}
	for(int i=1;i<=cnt[3];i++){
		ans+='3';
	}
	for(int i=1;i<=cnt[2];i++){
		ans+='2';
	}
	for(int i=1;i<=cnt[1];i++){
		ans+='1';
	}
	for(int i=1;i<=cnt[0];i++){
		ans+='0';
	}
	cout<<ans;
	return 0;
}
