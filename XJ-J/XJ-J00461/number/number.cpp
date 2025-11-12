#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a,b;
	char q;
	cin>>a;
	int z=0,x=0;
	for(int i=0;i<a.size();i++){
		if(a[i]>=48&&a[i]<=57){
			b[z]=a[i];
			x++;
			z++;
	}
}
	for(int i=0;i<x;i++){
		for(int j=0;j<x;j++){
			if(x==1){
				cout<<b;
				break;
			}
			else if(b[j]<b[j+1]){
				q=b[j];
				b[j]=b[j+1];
				b[j+1]=q;
		}
	}
}
	for(int i=0;i<x;i++){
		cout<<b[i];
}
	
	
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
	
} 

