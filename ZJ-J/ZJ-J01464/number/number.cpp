#include<bits/stdc++.h>
using namespace std;
int sum[20];
//8:35~9:00 , AC?
int main(){
	//freopen("number.in","r",stdin);unmber nmuber nubmer numebr numnre
	//freopen("number.out","W",stdout);
	freopen("number.in","r",stdin);
	freopen("number.out","W",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			sum[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=sum[i];j++){
			putchar(i+'0');
		}
	}
	return 0;
}
