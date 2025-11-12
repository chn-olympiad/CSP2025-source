#include<bits/stdc++.h>
using namespace std;
string nums;
int num[15];
int main(){
	freopen("num.in","r",stdin);
	freopen("num.out","w",stdout);
	cin>>nums;
	for(int i=0; i<nums.size(); i++){
		if(nums[i]>='0' && nums[i]<='9'){
			num[nums[i]-'0']++;
		}
	}	
	for(int i=9; i>=0; i--){
		for(int j=num[i]; j>=1; j--){
			cout<<i;
		}
	}
	
	return 0;
}
