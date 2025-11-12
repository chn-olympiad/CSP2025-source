#include<bits/stdc++.h>
using namespace std;
char str[10000000];
int num[11]={0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<strlen(str);i++){
		if(str[i]>='0'&&str[i]<='9'){
			num[str[i]-'0']+=1;
		}
	}
	for(int i=9;i>=0;i--){
		while(num[i]){
			cout<<i;
			num[i]--;
		}
	}
	return 0;
} 
