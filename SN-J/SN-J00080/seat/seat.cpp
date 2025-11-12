#include<bits/stdc++.h>
using namespace std;
int s[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	int rs=s[1];
	int rxy=0;
	int r_n=0,r_m=0;
	for(int i=1;i<=n*m;i++){
		for(int j=i+1;j<=n*m;j++){
			if(s[j]>s[i]){
				int a=s[i];
				s[i]=s[j];
				s[j]=a;
			}
			/*
			while(r_n>n){
				while(r_m>m){
					//I can not do it. 
				}
			}
			*/
		}
	}
	//sorry,I really can not do it.
	return 0;
}
