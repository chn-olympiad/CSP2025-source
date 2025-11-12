#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	string str;
	cin >> str;
	vector<int> num;
	for(int i = 0; i < str.length(); i++){
		if(str[i] == 48 || str[i] == 49|| str[i] == 50|| str[i] == 51|| str[i] == 52|| str[i] == 53|| str[i] == 54|| str[i] == 55|| str[i] == 56|| str[i] == 57){
			num.push_back((int)str[i] - 48);
		}
	}
	
	int cnt[10] = {0};
	for(int i = 0; i < num.size(); i++){
		if(num[i]==0) cnt[0]++;
		if(num[i]==1) cnt[1]++;
		if(num[i]==2) cnt[2]++;
		if(num[i]==3) cnt[3]++;
		if(num[i]==4) cnt[4]++;
		if(num[i]==5) cnt[5]++;
		if(num[i]==6) cnt[6]++;
		if(num[i]==7) cnt[7]++;
		if(num[i]==8) cnt[8]++;
		if(num[i]==9) cnt[9]++;
	}
	for(int i = 9; i >= 0; i--){
		while(cnt[i]--){
			cout << i;
		}
	}
	return 0;
}
