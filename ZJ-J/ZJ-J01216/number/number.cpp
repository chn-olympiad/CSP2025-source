#include <bits/stdc++.h>
using namespace std;
long long a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;
	cin >> str;
	for(long long i = 0;i<str.size();i++){
		char now = str[i];
		if('0'<=now && now<='9'){
			a[now-'0']++;
		} 
	}
	for(long long i = 9;i>=0;i--){
		for(long long j = 1;j<=a[i];j++){
			cout << i;
		}
	}
	return 0;
}
