#include<bits/stdc++.h>
using namespace std;
string s;
int lis[1000002];
int len;
int zzds(){
	int mp=len+1;
	while(--mp){
	
	for( int i=mp;i>0;i--){
		//cout<<" i"<<i<<"seff"<<lis[i]<<" "<<lis[i-1]<<endl;
		if(lis[i]>lis[i-1]){
			int ls;
			ls=lis[i-1];
			lis[i-1]=lis[i];
			lis[i]=ls;
		}
		if(lis[i]<lis[i+1]){
			int ls;
			ls=lis[i+1];
			lis[i+1]=lis[i];
			lis[i]=ls;
		}
	}
	}
	return 0;
}
int main(){
	preopen("number.in",r,stdin);
	preopen("number.out",w,stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0' && s[i]<='9'){
		lis[len]=s[i]-'0';len++;
		//cout<<lis[len]<<endl;

		}
	}
	zzds();
	for(int i=0;i<len;i++){
		cout<<lis[i];
	}
	return 0;
}
