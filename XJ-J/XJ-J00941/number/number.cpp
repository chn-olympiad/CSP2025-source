#include <bits/stdc++.h>
using namespace std;
int main(){
	char a;
	int b[10000];
	int j=0,x=0;
	for(int i=0;i<lengh(a);i++){
		if (char[i]==1 || char[i]==2 || char[i]==3 || char[i]==4 || char[i]==5 || char[i]==6 || char[i]==7 || char[i]==8 || char[i]==9 || char[i]==10){
			b[j]=a[i];
			j++;
		}
	}
	for(int p=0;p<j,p++;){
		for(int q=0;q<j-1,q++;){
			if(b[q]<b[q+1]){
				x=b[q];
				b[q]=b[q+1];
				b[q+1]=b[q];
			}
		}
	}
	cout<<b;
	return 0;
}
