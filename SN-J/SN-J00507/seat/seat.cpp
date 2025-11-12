#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
int c,r,q=1;
cin>>c>>r;
int n[c*r];
for(int i=0;i<=c*r-1;i++){
	cin>>n[i];	
}
for(int i=1;i<=c*r-1;i++){
	if(n[0]<=n[i]){
		q+=1;
	}
}
if(q%c!=0){
	cout<<q/c+1<<" ";
}else{
	cout<<q/c<<" ";
}
 if(q/c%2==0){
	cout<<q/r;
}else{
	cout<<r-q%r;
}
	return 0;
} 
