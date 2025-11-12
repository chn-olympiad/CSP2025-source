#include<bits/stdc++.h>
using namespace std;
bool cmd(int x,int y){
	return x>y;
}
string s;
int a[1000050]={};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >>s;
	int b=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[i]= s[i]-48;
			b++;
		}
	}
	sort(a,a+s.size(),cmd);
	if(a[0]==0){
		cout <<0;
	}
	else{
		for(int i=0;i<b;i++){
			cout <<a[i];
		}
	}
	
	return 0;
}
