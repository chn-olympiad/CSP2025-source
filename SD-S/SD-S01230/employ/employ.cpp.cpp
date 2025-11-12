#include<bits/stdc++.h>
using namespace std;
int c[500];
char s[500];
int main(){
	int n,m,x=0,y=0,p=0;
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>c[i];
		if(s[i]=1)x++;
		else
		y++;
		if(y>c[i])y++;
		if(x>=m)p++;
	}
	cout<<p;
	
	return 0;
}
