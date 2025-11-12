#include<bits/stdc++.h>
using namespace std;
char s[100000];
long long a[100000]={0};
void qsort(int x){
	for(int i=0;i<x;i++){
		a[(int)(s[i])]=(int)(a[i]);
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=0;i<=2;i++){
		cin>>s[i];
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=(int)(s[i]-'0');
		}
	}
	long long n=sizeof(s);
	qsort(n);
	for(long long i=n;i>=0;i--){
		cout<<a[i];
	}
	return 0;
} 
