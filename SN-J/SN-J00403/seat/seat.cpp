#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c[10000],max;
	cin>>a>>b;
	for(int i=1;i<=(a*b);i++){
		cin>>c[i];
		if(c[i]>c[i+1]>c[i+2]>c[i+3]){
			max=c[i];
			
		}else if(c[i+1]>c[i]>c[i+2]>c[i+3]){
			max=c[i+1];
		}else if(c[i+2]>c[i]>c[i+1]>c[i+3]){
			max=c[i+2];
		}else{
			max=c[i+3];
			}
	}
	cout<<a<<1;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	return 0;
}
