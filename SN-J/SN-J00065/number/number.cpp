//SN-J00065 冯思淦 韩城市桢州初级中学
#include<bits/stdc++.h>
using namespace std;
freopen("number1.in","r",stdin);
freopen("number1.out","w",stdout);
int a[15];
string s;
int main(){
	cin>>s;
	for(int i=0;i<s;i++){
		a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++)cout<<s[i];
		}
	return 0;
} 
