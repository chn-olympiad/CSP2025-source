#include<bits/stdc++.h>
using namespace std;
long long a,b,c,e=0,f=0,g=0,h=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>a>>b;
	c=a*b;
	long long d[c+5]={0};
	for(long long i=0;i<c;i++){
		cin>>d[i];
		if(i==0){
			e=d[i];
		}
		if(d[i]>e){
			f++;
		}
	}
	g=f/b;
	h=f%b;
	if(g%2==0){
		cout<<g+1<<" "<<h+1;
	}
	else{
	cout<<g+1<<" "<<b-h;	
	}
	return 0;
}
