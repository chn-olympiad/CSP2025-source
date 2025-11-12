#include<bits/stdc++.h>
using namespace std;
int cnt[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for (int i=0;i<s.size();i++){
		if (isdigit(s[i])){
			cnt[s[i]-'0']++;
		}
	}
	for (int i=9;i>=0;i--){
		while (cnt[i]--){
			putchar(i+'0');
		}
	}
	printf("\n");
	return 0;
}
