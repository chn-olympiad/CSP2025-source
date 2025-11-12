#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	string a;
	int d=0,b=0;
	long long y=0,x=1;
	cin>>a;
	for(int i=0;i<=1000001;i++){
		if(int('0')<=int(a[i]) and int(a[i])<=int('9')){
			if(int(a[i]-48)<=y%10){
				if(int(a[i]-48)==0){
					y=y*10;
				}
				else{
					y=y*10+int(a[i]-48);					
				}
			} 
			else{
				y=y+int(a[i]-48)*x;
			}
			x*=10;
		}
		if(a[i+1]==0){
			break;
		}
	} 
	cout<<y;
	return 0;
}
	
