#include<iostream>
#include<string>
using namespace std;
string numz[10005];
int main(){
	int mx=0;
	int b=0;
	for(int i=0;i<10005;i++){
		cin>>numz[i];
		if(numz[i]<=mx){
			b+=10;
			mx=numz[i]*10+mx;
		}
		else{
			int a=10;
			for(int j=0;j<mx;j++){
				if(numz[i]=mx/a){
					mx=numz[i]*a=mx;
				}
				a+=10;
			}
		}
	}
	cout<<mx;
	return 0;
}