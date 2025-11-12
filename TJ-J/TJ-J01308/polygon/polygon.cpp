#include <bits/stdc++.h>
using namespace std;

int a,b,f;
int g[5005];

int main(){
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>g[i];
	}
	
	for(int i=3;i<a;i++){
		for(int b1=0;b1<a;b1++){
			for(int b2=b1+1;b2<a;b2++){
				for(int b3=b2+1;b3<a;b3++){
					if((g[b1]>g[b2]&&g[b1]>g[b3])||(g[b1]>g[b3]&&g[b1]>g[b2])){
						b=g[b1];
					}else if((g[b1]>g[b2]&&g[b3]>g[b1])||(g[b2]>g[b1]&&g[b3]>g[b2])){
						b=g[b3];
					}else if((g[b2]>g[b1]&&g[b2]>g[b3])||(g[b2]>g[b3]&&g[b2]>g[b1])){
						b=g[b2];
					}
					if((g[b1]+g[b2]+g[b3])>b*2){
						f++;
						cout<<g[b1]<<' '<<g[b2]<<' '<<g[b3]<<' '<<endl;
					}
				}
			}
		}
	}
	cout<<f;
	return 0;
}
