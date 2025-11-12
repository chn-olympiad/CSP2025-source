#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin >> s;
	int cnt = 0,a[s.size()] = {10};
	for(int i = 0;i < s.size();i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[cnt] == int(s[i]) - 48;
			cnt++;
		}
	}
	int b[cnt] = {10};
	for(int i = 0;i < cnt;i++){
		for(int j = 0;j < s.size();j++){
			if(a[j] != 10 && a[j] != b[i]){
				b[i] = a[j];
				break;
			}
		}
	}
	for(int i = 0;i < cnt;i++){
		for(int j = i + 1;j < cnt;j++){
			if(b[i] < b[j]) swap(b[i],b[j]);
		}
	}
	int ans[cnt] = {10};
	for(int i = 0;i < cnt;i++){
		for(int j = 0;j < cnt;j++){
			for(int k = 0;k < cnt;k++){
				if(ans[j] != b[k]) ans[i] = b[k];
			} 
		}
		ans[i] = b[i];
	}
	for(int i = 0;i < cnt;i++){
		if(ans[i] == 10) continue;
		cout << ans[i];
	}
	return 0;
} 
