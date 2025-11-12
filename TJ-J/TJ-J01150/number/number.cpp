#include <bits/stdc++.h>
using namespace std;
const int MAX=0x7fffffff;
int b;
char c[100001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdin);
	cin>>c;
	int l=strlen(c);
	int a[l];
	for(int i=0;i<l;i++){
		if(c[i]-48<=9 && c[i]-48>=0){
			a[b]=c[i]-48;
			b++;
		}
	}
	int temp;
	for(int j=0;j<b;j++){
		for(int i=0;i<b;i++){
			if(a[j]>a[i]){
				temp=a[j];
				a[j]=a[i];
				a[i]=temp;
			}
		}
	}
	for(int i=0;i<b;i++){
		cout<<a[i];
	}
	return 0;
}

