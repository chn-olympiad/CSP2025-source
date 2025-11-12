#include <bits/stdc++.h>
using namespace std;
int b[1000010],c=0,d[1000010];
int main(){
	string a;
	int n;
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0' && a[i]<='9'){
			b[c]=a[i]-'0';
			c++;
		}
	}	
	for(int j=1;j<c;j++){
		for(int i=1;i<c;i++){
			if(b[i]>b[i-1]){
				n=b[i-1];
				b[i-1]=b[i];
				b[i]=n;
			}
		}
	}
		for(int i=0;i<c;i++){
		cout<<b[i];
	}
	
	return 0;
}
