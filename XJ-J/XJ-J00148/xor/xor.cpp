#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	freopen("xorin","r",stdin);
	freopen("xorout","w",stdout);
	int a,b,c[100]={},d=1,f=1,g;
	cin>>a>>b;
	g=a*b;
	for(int i=0;i<g;i++){
		cin>>c[i];
	}
	for(int l=0;l<g;l++){
		if(c[0]<c[l]){
			f++;
			if(f>b){
				f=f-b;
				d++;
			}
		}
	}
	cout<<d<<" "<<f;
	return 0;
	
}
	
