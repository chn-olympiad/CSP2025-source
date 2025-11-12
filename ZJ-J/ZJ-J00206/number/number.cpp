#include<bits/stdc++.h>
using namespace std;



int cnt[15];
string s;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<(int)(s.size());i++){
		char ch=s[i];
		if(ch>='0'&&ch<='9') cnt[ch-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=cnt[i];j++){
			putchar(i+'0');
		}
	}
	return 0;
}
