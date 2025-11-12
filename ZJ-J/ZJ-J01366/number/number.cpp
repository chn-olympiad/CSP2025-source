#include<bits/stdc++.h>
using namespace std;


string s;
vector<int> nums;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			nums.push_back((s[i]-'0'));
		}
	}
	
	
	sort(nums.begin(),nums.end());
	for(int i=nums.size()-1;i>=0;i--){
		cout<<nums[i];
	}
	cout<<endl;

	return 0;
}











//By StuffyWalk Problem 1

