#include <bits/stdc++.h>
using namespace std;
string s;
long long l = -1;
string f;
long long arr[15] = {};
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin>>s;
	for(long long i = 0; i < s.size(); i++){
		if(s[i] >= '0' && s[i] <= '9'){
			f += s[i];
			arr[s[i] - '0']++;
		}
	}
	for(long long i = 0; i < f.size(); i++){
		if((f[i] - '0') >= l){
			l = f[i] - '0';
		}
	}
	for(int i = 9; i >= 0; i--){
		if(arr[i] != 0){
			for(long long j = 1; j <= arr[i]; j++){
				cout<<i;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
