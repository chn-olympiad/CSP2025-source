#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
int n[10000],s[1000],z=0,m,b=0,a,j=0,c=0;
cin>>a;
cin>>n[a];	
	for(int i=0;i<a;i++){
		if (n[i]=1&&2&&3&&4&&5&&6&&7&&8&&9){
		n[i]=s[z];
		z++;
		}
		else{n[i]=0;}
	}
	while(z>b){
	for(int i=0,g=0;i<z;i++){
		if(s[i]<s[i+1]){
		m=s[i]; s[i]=s[i+1]; s[i+1]=m;
		}
		else{g++;}
	}	
b++;
}
while(j<z){
cout<<s[c];
j++;c++;
}
	return 0;
}
