//SN-J00900 胡志豪 汉滨区汉滨初级中学 
#include<iostream>
#include<stdio.h>
int ans[10];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	std::string s;
	std::cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			ans[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(ans[i]){
			std::cout<<i;
			ans[i]--;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
