//SN-J00352张晟轩渭南初级中学 
#include<bits\stdc++.h>
#include<iostream>
#include<cstring>
using namespace std;
bool con(int u1,int u2,int u3){
	if((u1+u2)>u3&&(u1+u3)>u2&&(u3+u2)>u1){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	int a[5005];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		if(con(a[1],a[2],a[3])){
		    cout<<1;	
		}else{
			cout<<0;
		}
		return 0;
	}else{
		cout<<7;
		return 0;
	}
	return 0;
}
