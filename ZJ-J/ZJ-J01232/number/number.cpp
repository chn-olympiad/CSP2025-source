#include<iostream>
#include<cstring>
char s[1000005];
int a[10];
int lena;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	std::cin>>s;
	for(int i=0;i<std::strlen(s);i++){
		if(s[i]>='0' && s[i]<='9'){
			a[s[i]-'0']++;
		}
	}	
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			std::cout<<i;
		}
	}
	return 0;
}
