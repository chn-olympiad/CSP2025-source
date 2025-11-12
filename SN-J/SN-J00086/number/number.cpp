#include <bits/stdc++.h>
using namespace std;
string a,am;
char an;
long long b[1000001],j=0,bb,n=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	am=a+"/";
	an=am[n];
	while(an!='/'){
		n++;
		an=am[n];
	}
	for(int i=0;i<n;i++){
		if(a[i]>=int('0')&&a[i]<=int('9')){
			b[j]=a[i]-int('0');
			j++;
		}
	}
	for(int m=0;m<j;m++){ 
		for(int n=1;n<j;n++){
			if(b[n-1]<b[n]){
				bb=b[n-1];
				b[n-1]=b[n];
				b[n]=bb;
			}
		}
	}
	for(int i=0;i<j;i++){
		printf("%lld",b[i]);
	}
	return 0;
}
