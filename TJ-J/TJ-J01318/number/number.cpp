#include<bits/stdc++.h>
using namespace std;
const int N=10e5;
char aa[N]={-1};
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a=0;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			aa[a]=s[i];
			a++;
		}
	}
	int q[10]={0};
	for(int i=0;i<a;i++){
		q[aa[i]-48]++;
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<q[i];j++){
			cout<<i;
		}
	} 
	//fclose(stdin);
	//fclose(stdout);
}
