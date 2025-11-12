#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	freopen("polygonin","r",stdin);
	freopen("polygonout","w",stdout);
	int a,b[100]={},c=0;
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>b[i];
	}
	for(int i=0;i<a;i++){
		cout<<b[i];
		c++;
	}
	cout<<c;
}
	
