#include<bits/stdc++.h>
using namespace std;
int c,r;
int temp=0;
int main(){
	cin >>c>>r;
	int a[c*r];
	for(int i=0;i<=c*r;i++){
		cin >>a[i];
	}
	for(int i=0;i<=c*r;i++){
		for(int j=0;j<=c*r;j--){
			if(a[i]>a[j+1]){
				a[j]=temp;
				temp=a[j-1];
			}
		}
	}
	
	return 0;
}
