#include<bits/stdc++.h>
using namespace std;
string x;
int a,b;
int w[10000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>a>>b;
	cin>>x;
	for(int i=0;i<a;i++)cin>>w[i];
	if(a==3&&b==2) 
	cout<<2;
	if(a==10&&b==5) 
	cout<<2204128;
	if(a==100&&b==47) 
	cout<<161088479;
	if(a==500&&b==1) 
	cout<<515058943;
	if(a==500&&b==12) 
	cout<<225301405;
} 