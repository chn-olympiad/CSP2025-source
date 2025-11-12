#include<bits/stdc++.h>
using namespace std;
string s;
bool flag=1;
int vis[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			int n=s[i]-'0';
			vis[n]++;
			if(n!=0) flag=0;
		}
	}
	if(flag){
		cout<<0;
		return 0;
	}
	for(int i=9;i>=0;i--){
		while(vis[i]){
			cout<<i;
			vis[i]--;
		}
	}
	return 0;
}
//100·Ö 
