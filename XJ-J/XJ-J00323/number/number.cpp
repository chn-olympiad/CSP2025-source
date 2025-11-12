#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int s,p=0,a=0,b=0,c=0,d=0,e=0,n=0,m=0,l=0,k=0;
	cin>>s;
	
		if(s<1000){
		if(s<100){
		if(s<10){
		cout<<s;
		return 0;
		}
		else{
		while(p<=s){
		p=p+10;
	    }
	    a=(p-10)/10;
	    b=s-(p-10);
	    if(a>=b){
	    cout<<a*10+b; 
		}
		else{
		cout<<b*10+a;
		}
		}
		}
		else{
		while(n<=s){
		n=n+100;
		}
		while(p<=s-(n-100)){
		p=p+10;
		}
		a=(n-100)/100;
		b=(s-(n-100)-(s-(n-100)-(s-(n-100))/10))/10;
		c=s-(n-100)-(s-(n-100))/10;
		if(a>=b>=c){
		cout<<a*100+b*10+c; 
		}
		else{
		if(a>=c>=b){
		cout<<a*100+b+c*10;
		}
		else{
		if(b>=a>=c){
		cout<<b*100+a*10+c;
		}
		else{
		if(b>=c>=a){
		cout<<b*100+c*10+a;
		} 
		else{
		if(c>=a>=b){
		cout<<c*100+a*10+b;
		}
		else{
		cout<<c*100+b*10+a;
		}
		}
							
		}
						
		}
		}
				
				
		}
					
		}
		
		return 0;
}
		
	
	
	
	
	
	
	
