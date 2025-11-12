#include<bits/stdc++.h>
using namespace std;
int main(){
int m,n,mn,a,b;
cin>>n>>m;
for(int i=0;m*n>i;i++){
	cin>>mn;
	a=mn;
	if(mn>a){
		b+=1;
	}
}cout<<b;
return 0;
} 
