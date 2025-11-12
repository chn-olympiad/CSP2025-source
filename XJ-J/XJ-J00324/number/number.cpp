#include<bits/stdc++.h>
using namespace std;
string a,b;
int maxn=-1,sum;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> a;
	int len=a.size();
	for(int i=0;i<=len-1;i++){
		if(a[i]=='9'){
			cout << 9;
		}
	}
	for(int i=0;i<=len-1;i++){
		if(a[i]=='8'){
			cout << 8;
		}
	}
	for(int i=0;i<=len-1;i++){
		if(a[i]=='7'){
			cout << 7;
		}
	}
	for(int i=0;i<=len-1;i++){
		if(a[i]=='6'){
			cout << 6;
		}
	}
	for(int i=0;i<=len-1;i++){
		if(a[i]=='5'){
			cout << 5;
		}
	}
	for(int i=0;i<=len-1;i++){
		if(a[i]=='4'){
			cout << 4;
		}
	}
	for(int i=0;i<=len-1;i++){
		if(a[i]=='3'){
			cout << 3;
		}
	}
	for(int i=0;i<=len;i++){
		if(a[i]=='2'){
			cout << 2;
		}
	}
	for(int i=0;i<=len-1;i++){
		if(a[i]=='1'){
			cout << 1;
		}
	}
	for(int i=0;i<=len-1;i++){
		if(a[i]=='0'){
			cout << 0;
		}
	}
	return 0;
}

