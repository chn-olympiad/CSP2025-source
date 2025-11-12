#include<bits/stdc++.h>
using namespace std;
int b[1000000];
int main(){
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
	string a;
	int n=0,s=0,temp;
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			n+=1;
			b[n]=a[i]-'0';
		}
	} 
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(b[j]<b[j+1]){
				temp=b[j];
				b[j]=b[j+1];
				b[j+1]=temp;
			}
		}
	} 
	for(int i=0;i<n;i++){
		cout<<b[i];
	}
	return 0;
} 
