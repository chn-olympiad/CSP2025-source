#include<bits/stdc++.h>
using namespace std;
long long b[15]={0};
int main(){
	char a;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>a){
		if(a=='1'){
			b[1]++;
		}
		if(a=='2'){
			b[2]++;
		}
		if(a=='3'){
			b[3]++;
		}
		if(a=='4'){
			b[4]++;
		}
		if(a=='5'){
			b[5]++;
		}
		if(a=='6'){
			b[6]++;
		}
		if(a=='7'){
			b[7]++;
		}
		if(a=='8'){
			b[8]++;
		}
		if(a=='9'){
			b[9]++;
		}
		if(a=='0'){
			b[0]++;
		}
		if(a=='q'||a=='w'||a=='e'||a=='r'||a=='t'||a=='y'||a=='u'||a=='i'||a=='o'||a=='p'||a=='l'||a=='k'||a=='j'||a=='h'||a=='g'||a=='f'||a=='d'||a=='s'||a=='a'||a=='z'||a=='x'||a=='c'||a=='v'||a=='b'||a=='n'||a=='m'){
		break;
	}	
	}
	for(long long i=0;i<b[9];i++){
		cout<<'9';
	}
	for(long long i=0;i<b[8];i++){
		cout<<'8';
	}
	for(long long i=0;i<b[7];i++){
		cout<<'7';
	}
	for(long long i=0;i<b[6];i++){
		cout<<'6';
	}
	for(long long i=0;i<b[5];i++){
		cout<<'5';
	}
	for(long long i=0;i<b[4];i++){
		cout<<'4';
	}
	for(long long i=0;i<b[3];i++){
		cout<<'3';
	}
	for(long long i=0;i<b[2];i++){
		cout<<'2';
	}
	for(long long i=0;i<b[1];i++){
		cout<<'1';
	}
	for(long long i=0;i<b[0];i++){
		cout<<'0';
	}
	return 0;
}
