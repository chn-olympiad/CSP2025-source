#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int a,b,t=0,he;
	cin>>a>>b;
	int c[a*b];
	cin>>c[0];
	he=c[0];
	for(int i=0;i<=a*b;i++){
		if(i!=0&&c[i]>c[i-1]){
			t=c[i] ;
			c[i-1]=t;
			c[i]=c[i-1];
		}
	}
	for(int j = 1;j<=a*b-1;j++){
		cin>>c[j];
		for(int i=0;i<=sizeof(c);i++){
			if(i!=0&&c[i]>c[i-1]){
				t=c[i] ;
				c[i-1]=t;
				c[i]=c[i-1];
			}
		}
	
	}
	for(int i=0;i<=a*b;i++){
		if(c[i]==he){
			cout<<(i)/b<<" "<<(i)%b;
		}
	}
}
