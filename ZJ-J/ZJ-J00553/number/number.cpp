#include<bits/stdc++.h>
std::string s;
int t[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	std::cin>>s;
	for(int i=0;s[i];i++){
		if(s[i]>='0'&&s[i]<='9'){
			t[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=t[i];j++){
			std::cout<<i;
		}
	}
	return 0;
}
