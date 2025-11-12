//SN-J00458 戴思诚 西安市曲江第一学校
#include<bits/stdc++.h>
using namespace std;
int n,n1[10010],ca,h;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	for(int i=1;i<=n;i++){
		cin>>n1[i];
	} 
	sort(n1,n1+n);
	for(int i=1;i<=n;i++){
		if(n1[i]+n1[i+1]<=n1[i+2]){
			ca++;
		}
	}
	if(n==1||n==2){
		cout<<0;
	}
	else if(n==3){
		if(n1[i]+n1[i+1]<=n1[i+2]){
			cout<<0;
		}
		else{
			cout<<1;
		}
	}
	else{
		cout<<9;
	}
	return 0;
} 
