#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
int n=0;
int m=0;
cin>>n>>m;
int a=n*m;
int b[a];
int c[a];
int da=0;
int da1=0;
int chengji=0;
int paiming=0;
int s=0;
int s1=0;
for(int i=0;i<n*m;i++){
	cin>>b[i];
}
chengji=b[0];
for(int j=0;j<n*m;j++){
	for(int i=0;i<n*m;i++){
	if(b[i]>da){
		da=b[i];
		da1=i;
	}
	}
c[j]=da;
b[da1]=0;
da=0;
da1=0;
}
//for(int i=0;i<n*m;i++){
//	cout<<c[i];
//}
for(int i=0;i<n*m;i++){
	if(c[i]==chengji){
		paiming=i;
	}
}
int zuo[n][m];
for(int i=1;i<=n;i++){
	if(i%2!=0){
		for(int j=1;j<=m;j++){
			zuo[i][j]=c[j];
			if(zuo[i][j]==chengji){
				s=i;
				s1=j;
				break;
				
			}
			
		}
	}
	else{
		for(int v=m;v>=0;v--){
			zuo[i][v]=c[v+1];
			if(zuo[i][v]==chengji){
				s=i;
				s1=v;
				break;
				
			}
		}
	}
}
cout<<s1+1<<" "<<s;

	return 0;
}
