#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6+9;
string s;
ll nums[N], lnum = 0;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(), cin.tie(0), cout.tie(0);
	cin>>s;
	for(ll i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			nums[lnum] = s[i]-'0';
			lnum++;
		}
	}
	sort(nums, nums+lnum);
	for(ll i=lnum-1;i>=0;i--){
		cout<<nums[i];
	}
	return 0;
}