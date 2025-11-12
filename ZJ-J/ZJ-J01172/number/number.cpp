#include<bits/stdc++.h>
using namespace std;
string s;
int ans,cnt[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int len=s.size()-1;
	for(int i=0;i<=len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(cnt[i]){
			cout << i;
			cnt[i]--;
		}
	}
	return 0;
}
