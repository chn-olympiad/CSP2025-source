//SN-J01157 饶子轩 西安市曲江第一中学 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,s,g=0;
	cin>>a>>s;
	int f=a*s;
	int d[f+5];
	for(int i=0;i<=f;i++){
		cin>>d[i];
	}
	for(int i=0;i<=f;i++){
		if(d[i]<=d[i+1]){
			g=d[i];
			d[i]=d[i+1];
			d[i+1]=g;
		}
	}
	
	return 0;
}
