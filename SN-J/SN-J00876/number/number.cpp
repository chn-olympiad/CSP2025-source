#include<bits/stdc++.h>
using namespace std;
string s;
int a[15],len=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	memset(a,0,sizeof(a));
	cin>>s;
	for(int i=0;i<s.length();i++){
		char temp;
		temp=s[i];
		if(int(temp-'0'>=0)&&int(temp-'0')<=9){
			len++;
			a[int(temp-'0')]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]!=0){
			a[i]--;
			cout<<i;
		}
	}
	return 0;
} 
