#include <bits/stdc++.h>
using namespace std;
int ans[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for (int i=0;i<s.size();i++){
		if (s[i]>='0'&&s[i]<='9'){
			ans[s[i]-'0']++;
		}
	}
	for (int i=9;i>=0;i--){
		if (ans[i]!=0){
			int n=0;
			n=ans[i];
			for (int j=1;j<=n;j++){
				cout << i;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
