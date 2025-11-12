#include<iostream>
#include<cmath>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char n;
	int m,a[101],b[101];
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	for(int i=1;i<= strlen(a);i++) {
		if(a[i]>=char('0')&&a[i]<=char('9')) {
			b[i]=a[i];
		}
	}
	for(int i=1;i<=strlen(a);i++) {
		for(int i=1;i<=strlen(a);i++) {
			if(a[i]<=a[i+1]) {
				m=a[i];
				a[i]=a[i+1];
				a[i+1]=m;
			}
		}
	}
	for(int i=1;i<=n;i++) {
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	
}
