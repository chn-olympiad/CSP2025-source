#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[1000005];
	int a[10]={0};
	cin>>s;
	for(int i=0;i<strlen(s);i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]!=0){
			cout<<i;
			a[i]--;
		}
	}
	//cout<<s[0]<<strlen(s);
}
