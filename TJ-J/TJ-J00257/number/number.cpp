#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 4;
int num[MAX] , num_cnt = 0;


int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	string s;
	cin >> s;
	for(int i = 0;i < s.length();i ++){
		if(s[i] >= '0' && s[i] <= '9'){
			num[num_cnt] = s[i] - '0';
			num_cnt ++;
		}
	}
	sort(num,num+num_cnt);
	
	for(int i = num_cnt - 1;i >= 0;i --){
		cout << num[i];
	}
	
	return 0;
}
