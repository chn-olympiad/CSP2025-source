//SN-J00042 何沐宸 延安市安塞区高级中学 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a=0,b[100]={0},aa=0;
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>b[i];
	}
	
	for(int i=0;i<a;i++){
		if(b[i]+b[i+1]>b[i+2]){
		aa++;
	}
	}
	cout<<aa+a;
	return 0;
}
