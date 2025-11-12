#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a,c=0;
	cin>>a;
	int b[a];
	for(int i=0;i<a;i++){
		cin>>b[i];
		if(b[i]>c){
			c=b[i]
		}
	}
	if(a==1 or a==2){
		cout<<0;
	}
	if(a==3){
		if(b[1]+b[2]+b[0]>c*2)
			cout<<1;
		else
			cout<<0;
	}
	if(b[a]==1){
		cout<<(a-3)*2+1;
	}
	return 0;
}
