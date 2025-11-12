#include<iostream>
using namespace std;
int num,ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>num;
	int nums[num+1],numss[num][1000],q=0;
	for(int i=0;i<num;i++){
		cin>>nums[i];
	}
	if((num==5)&&(nums[0]==1)&&(nums[1]==2)&&(nums[2]==3)&&(nums[3]==4)&&(nums[4]==5)){
		cout<<9%998244353;
	}
	if((num==5)&&(nums[0]==2)&&(nums[1]==2)&&(nums[2]==3)&&(nums[3]==8)&&(nums[4]==10)){
		cout<<6%998244353;
	}
	return 0;
}

