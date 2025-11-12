#include<bits/stdc++.h>
using namespace std;
string a;
int b[100010],c[100010],x,y;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]-48>48){
			b[i]=1e9+1;
		}else{
			b[i]=a[i]-48;
		}
	}
	for(int i=0;i<a.size();i++){
		if(b[i]!=1e9+1){
			if(b[i]>=0){
				c[x]=b[i];
				x++;
			}
		}
	}
	for(int i=0;i<x;i++){
		for(int j=0;j<x;j++){
			if(c[j]<c[j+1]){
				y=c[j];
				c[j]=c[j+1];
				c[j+1]=y;
			}
		}
	}
	for(int i=0;i<x;i++){
		cout<<c[i];
	}	
	return 0;
}
