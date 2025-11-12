#include <iostream>
#include <string>
using namespace std;
int main(){
	string s;
	int x,y;
	x=0;
	cin>>s;
	for(int i=1;i<=s;i++){
		if(s%10==1||s%10==2||s%10==3||s%10==4||s%10==5||s%10==6||s%10==7||s%10==8||s%10==9){
			x=x*10+s%10;
			y++;
		}
		s=s/10;
	}
} 
