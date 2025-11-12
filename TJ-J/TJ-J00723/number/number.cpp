#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[1000000];
	for(int i=0;i<=100000;i++){
		a[i]='!';
	}
	cin >> a;
	int i=0,n1=0,n2=0,n3=0,n4=0,n5=0,n6=0,n7=0,n8=0,n9=0,n0=0;
	while(a[i]!='!'){
		if(a[i]=='0'){
			n0++;
		}
		if(a[i]=='9'){
			n9++;
		}
		if(a[i]=='8'){
			n8++;
		}
		if(a[i]=='7'){
			n7++;
		}
		if(a[i]=='6'){
			n6++;
		}
		if(a[i]=='5'){
			n5++;
		}
		if(a[i]=='4'){
			n4++;
		}
		if(a[i]=='3'){
			n3++;
		}
		if(a[i]=='2'){
			n2++;
		}
		if(a[i]=='1'){
			n1++;
		}
		i++;
	}
	for(int j=0;j<n9;j++){
		cout << 9;
	}
	for(int j=0;j<n8;j++){
		cout << 8;
	}
	for(int j=0;j<n7;j++){
		cout << 7;
	}
	for(int j=0;j<n6;j++){
		cout << 6;
	}
	for(int j=0;j<n5;j++){
		cout << 5;
	}
	for(int j=0;j<n4;j++){
		cout << 4;
	}
	for(int j=0;j<n3;j++){
		cout << 3;
	}
	for(int j=0;j<n2;j++){
		cout << 2;
	}
	for(int j=0;j<n1;j++){
		cout << 1;
	}
	for(int j=0;j<n0;j++){
		cout << 0;
	}
	return 0;
} 
