#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;int t=0,p=0,P=0;
	cin>>n>>m;
	char s[n+1]=" ";
	int c[n+1]={0};
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int j=1;j<=n;j++){
	for(int i=j;i<=n;i++){
		if(s[i]=='1'&&i-p<=c[i]){
			p++;}
			
		
		
	}if(p>=m)
		P++;
		p=0;}for(int j=1;j<=n;j++){
	for(int i=j;i<=n;i++){
		if(s[i]=='1'&&i-p<=c[i]){
			p++;}
			
		
		
	}if(p>=m)
		P++;
		p=0;}
	cout<<P;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
