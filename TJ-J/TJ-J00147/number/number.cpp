#include<iostream>
#include<string>
using namespace std;
string a;
int len=0,i=0;
int check(string a){
	while(a[i]!='\0'){
		len++;
		i++;
	}
	for(int i=0;i<len;i++){
		int j=a[i]-0;
		if(((97<=j)&&(j<=122))||((47<=j)&&(j<=59))){
			int passq;	
		}else{
			cout<<"input error";
			return 0;
		}
	}
}
int my_max(string a){
	if(!check(a)){
		return 0;
	}
	int nums[len],maxnum=0,flag=0,flax=0,m=0;
	for(int i=0;i<len;i++){
		int j=a[i]-0;
		if((47<=j)&&(j<=59)){
			nums[flag]=a[i]-48;
			flag++;
		}
	}
	for(int i=0;i<flag;i++){
		int maq=-1;
		for(int j=i;j<flag;j++){
			if(maq<nums[j]){
				maq=nums[j];
				flax=j;
			}
		}swap(nums[m],nums[flax]);m++;
	}
	for(int i=0;i<flag;i++){
		maxnum=(maxnum+nums[i])*10;	
	}maxnum/=10;
	return maxnum;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	cout<<my_max(a);
	return 0;
}
