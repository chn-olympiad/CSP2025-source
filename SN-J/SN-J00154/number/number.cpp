#include<iostream>
#include<cstring>
#define maxsize 1000001
using namespace std;
int a[10]={},i;
void putin(){
	string c;
	char b[maxsize];
	cin>>c;
	for(i=0;i<=c.length();i++){
		b[i]=c[i];
		if(int(b[i])>=48&&int(b[i])<=57){
			a[int(b[i])-48]++;
		}else if(int(b[i])<=122&&int(b[i])>=97){
		}else{
			break;
		}
	}
	
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	putin();
	for(i=9;i>=0;i--){
		while(a[i]!=0){
			cout<<i;
			a[i]--;
		}
	}
	return 0;
}
