#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int n;
	vector<char> c;
	vector<int> nums; 
	cin>>s;
	for(int i=0;i<s.length();i++){
		c.push_back(s[i]);
		if (s[i]-48<=9) nums.push_back(s[i]-48);
	}
	sort(nums.begin(),nums.end(),cmp);
	for(int i=0;i<nums.size();i++){
		cout<<nums[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
