#include<bits/stdc++.h> 
using namespace std;
int a[10000];
char c[1000];
int s(char a){
	for(int i=0;i<=25;i++){
		if('a'+i==a){
			return 0;
		}
	}
	return 1;
}
int main(){
	for(int i=1;i<=100;i++){
		a[i]=-1;
	}
	long long z,q=1,t,h=0;
	cin>>c;
	for(int i=0;i<=100;i++){
		if(s(c[i])){
			a[q]=c[i];
			a[q]-=48;
			q++;
		}
	}
	for(int i=1;i<=100;i++){
		for(int j=i;j>1;j--){
			if(a[j]>a[j-1]){
				t=a[j];
				a[j]=a[j-1];
				a[j-1]=t;
			}
		}
	}
	for(int i=1;i<=100;i++){
		if(a[i]<0){
			return 0;
		}
		cout<<a[i];
	}
	return 0;
}
