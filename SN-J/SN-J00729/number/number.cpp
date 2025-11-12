#include <bits/stdc++.h>
using namespace std;
char a[1000001];
int b[1000001];
int c[10];
int e,d,n=-1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<=1000000;i++){
		b[i]=a[i];
		if(a[i]==0) break;
		n++;
	}
	for(int i=0;i<=n;i++){
		if(b[i]>=48&&b[i]<=57){
			 e=b[i]-48;
			if(e>d) d=e;
			c[e]++;
		}
	}
	for(int i=d;i>=0;i--){
		while(c[i]!=0){
			cout<<i;
			c[i]--;
		}
	}
	return 0;
}
