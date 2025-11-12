#include<iostream>
using namespace std;
short abc(char a);
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char zf,a[1000000];
	int count1=0,count2=9,ac[10]={0},j=0;
	do{
		cin.getline(a,1000000);
		zf=a[j];
		j++;
		if(isdigit(zf)){
			short b=abc(zf);
			ac[b]++;
			count1++;
		}
	}
	while(zf!='\0');
	for(int i=0;count1>0;){
		int b=ac[count2];
		if(b<=0){
			count2--;
		}
		ac[count2]--;
		if(ac[count2]>=0){
			cout<<count2;
			count1--;
		}
	}
}
	
	
	
	
	

	
	
	
	
	
	
	
	
	
	
	
	
	
short abc(char a){
	if(a=='0')return 0;
	if(a=='1')return 1;
	if(a=='2')return 2;
	if(a=='3')return 3;
	if(a=='4')return 4;
	if(a=='5')return 5;
	if(a=='6')return 6;
	if(a=='7')return 7;
	if(a=='8')return 8;
	if(a=='9')return 9;
}
