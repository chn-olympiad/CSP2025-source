#include<bits/stdc++.h>
using namespace std;
int tong[100]; 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a,b;
	int c=0,s=0;
	cin>>a; 
	while(b!=a){
		b+=a[c];
		if('0'<=a[c]&&a[c]<='9'){
			int f=a[c]-48;
			tong[f]++;
		}
		c++;
	}
	for(int i=9;i>=0;i--){
		for(int j=tong[i];j>0;j--){
			cout<<i;
		}
	}
	return 0;
}
