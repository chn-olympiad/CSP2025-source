#include<bits/stdc++.h>
using namespace std;
int ans[1000007];
int main(){
	
	
	string s;
	long long k = 0;
	cin >> s;
	for(long long i = 0 ; i < s.length(); i++){
		if(s[i]>='0' && s[i] <= '9'){
			ans[k]=s[i]-'0';
			k++;
		}
	}
	for(long long i = 0 ; i <= k ; i++){
		for(long long j = 0 ; j <= k - i ; j++){
			if(ans[j] < ans[j+1]){
				swap(ans[j], ans[j+1]);
			}
		}
	}
	for(long long i = 0 ; i < k ; i++){
		printf("%d", ans[i]);
	}
	
	
	return 0;
}
