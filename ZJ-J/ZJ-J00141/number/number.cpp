#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin>>s;
	vector<int>nums;
	for(int i=0;i<s.size();i++)if(isdigit(s[i]))nums.push_back(int(s[i]-'0'));
	sort(nums.begin(),nums.end());
	for(int i=nums.size()-1;i>=0;i--)cout<<nums[i];
	
	return 0;
}