#include"bits/stdc++.h"
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int n=0;
	int b[a.size()]={0};
	for(int i=0;i<=a.size();i++){
		if(a[i]=='0'){
			b[i+1]=0;
			n=n+1;
		}else if(a[i]=='1'){
			b[i+1]=1;
			
		}else if(a[i]=='2'){
			b[i+1]=2;
			
		}else if(a[i]=='3'){
			b[i+1]=3;
			
		}else if(a[i]=='4'){
			b[i+1]=4;
			
		}else if(a[i]=='5'){
			b[i+1]=5;
			
		}else if(a[i]=='6'){
			b[i+1]=6;
			
		}else if(a[i]=='7'){
			b[i+1]=7;
			
		}else if(a[i]=='8'){
			b[i+1]=8;
			
		}else if(a[i]=='9'){
			b[i+1]=9;
			
		}
	}sort(b+1,b+a.size()+1);
	int flag=0;
	for(int i=a.size();i>=1;i--){
		if(b[i]!=0){
			cout<<b[i];
			flag=1;
		}
	}if(flag==0){
		n=1;
	}
	for(int i=1;i<=n;i++){
		cout<<"0";
	}return 0;
} 
