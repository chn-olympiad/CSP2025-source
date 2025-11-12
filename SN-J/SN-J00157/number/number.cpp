#include<bits/stdc++.h>
using namespace std;
int x=0;
int e=0;
int f=10;
int s[1000000];
int b[1000000];
int c,d;
int main(){
	freopen("number.in","r",stdin),
	freopen("number.out","w",stdout),	
	cin>>d;
	for(int i=1;i<1000000;i++){
		s[i]=d%f;
		if((d/f)<10){
			s[i+1]=d;
			break;
		}
		f=f*10;
		x=x+1;
	}
	for(int i=1;i<=x;i++){
		c=s[i];
		s[i]=s[x+1-i];
		s[x+1-i]=c;
	}
	for(int i=1;i<=1000000;i++){
		if(s[i]<=9&&s[i]>=1){
			b[i]=s[i];
			e=e+1;
		}
	}
	for(int j=1;j<=e;j++){
		for(int i=1;i<=e;i++){
		    if(b[i]>b[i+1]){
			    c=b[i];
			    b[i]=b[i+1];
			    b[i+1]=c;
		    }
	    }
	}
	for(int i=1;i<=e;i++){
		cout<<b[i];
	}
	return 0;
} 
