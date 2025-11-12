#include <bits/stdc++.h>
using namespace std;

string s;
int nums[1000010],numcnt;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int slen=s.length();
	int minnum=10;
	for(int i=0;i<slen;i++){
		if(s[i]>='0'&&s[i]<='9'){
			//cout<<s[i]-'0'<<"\n";
			nums[numcnt]=s[i]-'0';
			numcnt++;
			//cout<<s[i];
		}
	}
	//cout<<nums[0]<<nums[1]<<nums[2]<<nums[3]<<nums[4]<<"\n";
	sort(nums,nums+numcnt,cmp);
	//cout<<numcnt<<" "<<slen<<"\n";
	//cout<<nums[0]<<nums[1]<<nums[2]<<nums[3]<<nums[4]<<"\n";
	for(int i=0;i<numcnt;i++){
		cout<<nums[i];
	}
	return 0;
}
