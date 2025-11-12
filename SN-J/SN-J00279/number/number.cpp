#include<iostream>
using namespace std;
char a[1000005];
int b[1000005],c=0,x;
int d[10];
int main(){
	cin>>a;
	for(int i=0;i<1000005;i++){
		if(a[i]=='\0'){
			break;
		}
		if(a[i]>='0'&&a[i]<='9'){
			x=a[i]-'0';
			d[x]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<d[i];j++){
			cout<<i;
		}
	}
	return 0;
} 
