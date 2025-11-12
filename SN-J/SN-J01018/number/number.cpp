//SN-J01018  赵晗羽  西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
int a[10]={0,0,0,0,0,0,0,0,0,0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')a[int(s[i])-48]++;
	}
	for(int i=9;i>=0;i--){
		if(a[i]){
			for(int j=0;j<a[i];j++)cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
