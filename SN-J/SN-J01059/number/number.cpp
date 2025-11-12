#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int a[10] = {0};
	for(int i = 0;i < s.size();i++){
		if(s[i] >= '0'&&s[i] <= '9'){
			int t = s[i]-'0';
			a[t]++;
		}
	}
	for(int i = 9;i >= 0;i--){
		int j = a[i];
		while(j--){
			cout << i;
		}
	}
	return 0;
} 
