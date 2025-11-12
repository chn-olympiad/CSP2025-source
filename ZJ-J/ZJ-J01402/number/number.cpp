#include<iostream>
#include<cstring>
using namespace std;
string s;
int sum[10]={};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]<='9'&&s[i]>='0'){
			sum[s[i]-48]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(;sum[i]>0;sum[i]--){
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
