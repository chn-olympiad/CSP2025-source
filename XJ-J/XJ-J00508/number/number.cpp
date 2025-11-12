#include<iostream>
using namespace std;
int main (){
	freopen("number.in","r","stdin");
	freopen("number.out","w","stdout");
	char a[10];
	char z[10];
	int o=0 ;
	for(int n=0;n<=10-1;n++){
		cin>>a[n];
	}
	for(int b=0;b<=10-1;b++){
		if(a[b]=='0'||a[b]=='1'||a[b]=='2'||a[b]=='3'||a[b]=='4'||a[b]=='5'||a[b]=='6'||a[b]=='7'||a[b]=='8'||a[b]=='9'){
			z[b]=a[b];
		}
	}
	for(int q=0;q<=10-1;q++){
		for(int w=0;w<=50-q-1;w++){
			if(z[w]<z[w+1]){
			 o=z[w];
			 z[w]=z[w+1];
			 z[w+1]=o;
		}
	}
}
	for(int x=0;x<=50;x++){
		cout<<z[x];
	}
	return 0;
} 
