#include<bits/stdc++.h>
using namespace std;

#define int long long
string s;
int cnt[114];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >>s;
	for(int i =0;i<s.size();i++){
		cnt[s[i] - '0'] ++;
	}
	for(int i =0;i<cnt[9];i++){
		cout << '9';
	}
	for(int i =0;i<cnt[8];i++){
		cout << '8';
	}
	for(int i =0;i<cnt[7];i++){
		cout << '7';
	}
	for(int i =0;i<cnt[6];i++){
		cout << '6';
	}
	for(int i =0;i<cnt[5];i++){
		cout << '5';
	}
	for(int i =0;i<cnt[4];i++){
		cout << '4';
	}
	for(int i =0;i<cnt[3];i++){
		cout << '3';
	}
	for(int i =0;i<cnt[2];i++){
		cout << '2';
	}
	for(int i =0;i<cnt[1];i++){
		cout << '1';
	}
	for(int i =0;i<cnt[0];i++){
		cout << '0';
	}
	return 0;
}
