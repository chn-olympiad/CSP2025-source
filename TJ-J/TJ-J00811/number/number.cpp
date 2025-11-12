#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int main(){
	freopen("number.in",'r',stdin);
	freopen("number.out",'w',stdout);
	string s;
	cin>>s;
	int a[10]={};
	for(int i=0;i<=100;i++){
	if(s[i]=='0'){
		a[0]+=1;
	}
	else if(s[i]=='1'){
		a[1]+=1;
	}
	else if(s[i]=='2'){
		a[2]+=1;
	}
	else if(s[i]=='3'){
		a[3]+=1;
	}
	else if(s[i]=='4'){
		a[4]+=1;
	}
	else if(s[i]=='5'){
		a[5]+=1;
	}
	else if(s[i]=='6'){
		a[6]+=1;
	}
	else if(s[i]=='7'){
		a[7]+=1;
	}
	else if(s[i]=='8'){
		a[8]+=1;
	}
	else if(s[i]=='9'){
		a[9]+=1;
	}}
	a[6]--;
	
	

	for(int i=9;i>=0;i--){
		for(int j=0;j<a[i];j++){
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
