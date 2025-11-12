#include<bits/stdc++.h>
using namespace std;
int x[114514],y=0,z=0,a=0,b=0,c=0;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>a>>b;
	c=a*b;
	for(int i=0;i<c;i++) {
		cin>>x[i];
	}sort(x,x+1);
		int r=x[1];
		for(int i=0;i<a;i++) {
			if(x[i]=r){
				y=1;
			}
			else if(x[i]!=r){
				for(int j=0;j<a+a;j++){
					if(x[i]=r){
						y=2;
					}
					else if(x[i]!=r){
						if(j>=c){
							break;
					}
				}
			}
		}	
	} 
	for(int i=0;i<a;i++) {
		if(x[i]=r){
			z=1;
		}
	}
	return 0;
}
