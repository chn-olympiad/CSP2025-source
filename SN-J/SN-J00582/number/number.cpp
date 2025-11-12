#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int ans[10],l;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0;i <=strlen(s)-1;i++){
		if(isdigit(s[i])){
			ans[s[i]-48]++;
		}
	}
	for(int k = 9;k >= 0;k--){
		for(int j = ans[k]-1;j >= 0;j--){
			cout << k;
		}
	}	
	return 0;
}
