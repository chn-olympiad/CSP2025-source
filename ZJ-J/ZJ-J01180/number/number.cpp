#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a,b;
	int c=0;
	cin>>a;
	
	for (int i=0;i<a.size();i++){
		if(a[i]=='9'){
			cout<<9;
		} 
		if (a[i]>='0' and a[i]<='8'){
			b[c]=a[i];
			c++;
		}
		
	}
	for (int i=0;i<c;i++){
		if (b[i]=='8'){
			cout<<8;
		}
	}
	for (int i=0;i<c;i++){
		if (b[i]=='7'){
			cout<<7;
		}
	}
	for (int i=0;i<c;i++){
		if (b[i]=='6'){
			cout<<6;
		}
	}
	for (int i=0;i<c;i++){
		if (b[i]=='5'){
			cout<<5;
		}
	}
	for (int i=0;i<c;i++){
		if (b[i]=='4'){
			cout<<4;
		}
	}
	for (int i=0;i<c;i++){
		if (b[i]=='3'){
			cout<<3;
		}
	}
	for (int i=0;i<c;i++){
		if (b[i]=='2'){
			cout<<2;
		}
	}
	for (int i=0;i<c;i++){
		if (b[i]=='1'){
			cout<<1;
		}
	}
	for (int i=0;i<c;i++){
		if (b[i]=='0'){
			cout<<0;
		}
	}
	return 0;
}
