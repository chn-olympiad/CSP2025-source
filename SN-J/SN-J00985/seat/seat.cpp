#include<bits/stdc++.h>
using namespace std;
int main(){
	int s,a,b,r,q=1,w=1,d,c;
	cin>>s>>b;
	for(int i=1;i<=(s*b);i++){
		cin>>a;
		if(i==1){
			r=a;
		}
		if(a>r and w%2!=0){
			q++;
			if(q>=b and a>r){
				w+=1;
				
			}
		}else if(w%2==0){
				q--;
				if(q==1 and a>r){
					q=1;
					w+=1;
				}
			}
		if(a<r or i==(s+b) and a>r){
			d=w;
			c=q;
			cout<<d<<" "<<q;
				return 0;
		}
	}
	
	return 0;
}
