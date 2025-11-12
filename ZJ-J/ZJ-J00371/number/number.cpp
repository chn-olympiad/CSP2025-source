#include<bits/stdc++.h>
using namespace std;
string s;
int le,t,ans[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	le=s.length();
	for(int i=0;i<le;i++){
		t=(int)(s[i]-'0');
		if(0<=t&&t<=9){
			ans[t]++;
		}
	}
	for(int i=9;i>=0;i--){
		if(ans[i]!=0){
			for(int j=0;j<ans[i];j++)cout<<i;
		}
	}
}