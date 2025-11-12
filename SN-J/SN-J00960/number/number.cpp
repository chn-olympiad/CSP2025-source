//衣嘉鹏 SN-J00960 西安市曲江第一学校 
#include<bits/stdc++.h>
using namespace std;
int a;
int b,c,d;
int main(){
cin>>a;
	for(int i=1;;i++){
		if('0'<a%10<'9'){
		b=b*10+a%10;
		}
		a=a/10;
		if(a==0){
			break;
		}
	}
	for(int j=1;j<=10000;j++){
	if(j>=2){
	b=c;
	c=0;
	}
	for(int i=1;;i++){
		cout<<c<<" "<<b<<endl;	
		if(b%10>b%100/10){
			c=c*10+b%10;
			b=b/10;
		}else if(b%100/10>b%10){
			c=c*10+b%100/10;
			d=b%10;
			b=b/100*10+d;
		}else{
			c=c*10+b%10;
			b=b/10;
		}
		if(b==0){
			break;
		}				
	}

	}

cout<<c;
              
	return 0;
}
