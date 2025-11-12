#include<bits/stdc++.h>
using namespace std;

string s;

int nums[10];
int len = 0;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(nums,0,sizeof(nums));
	cin >> s;
	len = s.length();
	for(int i = 0;i < len;++i){
		if(s[i] >= '0' && s[i] <= '9'){
			++nums[s[i] - '0'];
		}
	}
	for(int i = 9;i >= 0;--i){
		for(int j = 0;j < nums[i];++j){
			cout << i;
		}
	}
	return 0;
}
