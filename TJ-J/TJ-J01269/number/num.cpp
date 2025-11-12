#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int x=0,num=0;
	sting n[1001];
	for(int i;i<=n;i++)
		cin>>s[i];
	for(int i=0;i<a;i++){
		if(isdigit(s[i])){
			int j=i;
			while(isdigit(s[j])){
				n[x]*=10;
				n[x]+=s[j];
			}
			x+=1;
		}
	}
	for(int i=0;i<a;i++){
		for(int j=i;j<a;j++){
			if(n[i]>n[j]){
				int m=n[i];
				n[i]=n[j];
				n[j]=m;
			}
		}
	}
	for(int i=0;i<a;i++){
		num*=10;
		num+=n[i];
	}
	cout<<num;
	return 0;
} 
