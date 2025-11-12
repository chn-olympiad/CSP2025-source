#include<bits/stdc++.h>
using namespace std;
int a[12];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,t;
	int a[1005],op=0,cnt=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(int(s[i])>=49&&int(s[i])<=57){
			a[op]=int(s[i])-48;
			op++;
		}else if(int(s[i])==48){
			cnt++;
		} 
	}
	sort(a,a+op);
	for(int i=op-1;i>=0;i--){
		cout<<a[i];
	}
	for(int i=0;i<cnt;i++){
		cout<<0;
	}
	return 0;
}
