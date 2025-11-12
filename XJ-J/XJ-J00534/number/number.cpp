#include <bits/stdc++.h>
using namespace std;
int main(){
	int n=1;
	char a,s[1000001],b[1000001];
	cin>>s;
	for(int i=1;i<=1000001;i++){
		if(s[i]>90){
			b[n]=s[i];
			n++;
		}
	}
	for(int i=1;i<=1000001;i++){
		if(b[i]<b[i+1]){
			a=b[i];
			b[i]=b[i+1];
			b[i+1]=a;
		}
	}
	for(int i=1;i<=1000001;i++){
		cout<<b[i];
	}
	return 0;
}
