//SN-J00919 范任哲 延安市宝塔区高新学校（延安无锡实验学校） 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in",stdin);
	freopen("number.out",stdout);
	char s[1000002];
	int s1=0,s2=0,s3=0,s4=0,s5=0,s6=0,s7=0,s8=0,s9=0,s0=0;
	scanf("%s",s);
	for(int i=0;i<strlen(s);i++){
		if(s[i]=='0'){
			s0++;
		}else if(s[i]=='1'){
			s1++;
		}else if(s[i]=='2'){
			s2++;
		}else if(s[i]=='3'){
			s3++;
		}else if(s[i]=='4'){
			s4++;
		}else if(s[i]=='5'){
			s5++;
		}else if(s[i]=='6'){
			s6++;
		}else if(s[i]=='7'){
			s7++;
		}else if(s[i]=='8'){
			s8++;
		}else if(s[i]=='9'){
			s9++;
		}
	}
	for(int i=0;i<s9;i++){
		cout<<9;
	}
	for(int i=0;i<s8;i++){
		cout<<8;
	}
	for(int i=0;i<s7;i++){
		cout<<7;
	}
	for(int i=0;i<s6;i++){
		cout<<6;
	}
	for(int i=0;i<s5;i++){
		cout<<5;
	}
	for(int i=0;i<s4;i++){
		cout<<4;
	}
	for(int i=0;i<s3;i++){
		cout<<3;
	}
	for(int i=0;i<s2;i++){
		cout<<2;
	}
	for(int i=0;i<s1;i++){
		cout<<1;
	}
	for(int i=0;i<s0;i++){
		cout<<0;
	}
	return 0;
}
