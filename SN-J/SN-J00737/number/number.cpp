#include<bits/stdc++.h>
using namespace std;
const int N=10;
int n;
char a[N];
int b[N];
int x;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    while(cin>>a[x]){
    	x++;
	}
//	for(int i=0;i<8;i++){
//		cin>>a[i];
//	}
    for(int j=0;j<x;j++){
		if(a[j]>='0' && a[j]<='9'){
			b[n]=a[j]-'0';
			n++;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(b[i]>b[j]){
				int c=b[i];
				b[i]=b[j];
				b[j]=c;
			}
		}
	}
	int m=0;
	for(int k=0;k<n;k++){
//		cout<<b[k]<<endl;
		m=m*10+b[k];
	}
	cout<<m<<endl;
    return 0;
}

