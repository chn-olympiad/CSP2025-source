#include<bits/stdc++.h>
using namespace std;
char a[1000001];
int b[1000200],c=0;
int big(int n,int m){
	return n>m;
}
int main(){

	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	
	for(int i=0; i<sizeof(a); i++){
		if(a[i]-'0'>=0 && a[i]-'0'<=9){
			b[c]=a[i]-'0';
			c++;
		}
	}

	
	sort(b,b+c,big);
	for(int i=0; i<c; i++) cout<<b[i];
	return 0;
}