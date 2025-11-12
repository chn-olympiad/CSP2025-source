#include<iostream>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a,e;
	cin>>a;
	int b[a-1];
	for(int i=0;i<=a-1;i++){
		cin>>b[i];
	}
	for(int i=0;i<=a;i++){
		for(int J=0;J<=a;J++){
		if(b[i]<b[J]){
			b[i]=e;
			b[i]=b[J];
			b[J]=b[i]
		}
		}
	}
	for(int i=0;i<=;i++){
		
	} 
	return 0;
}
