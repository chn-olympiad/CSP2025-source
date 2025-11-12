#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m,s1,s2,s3,s4;
cin>>n>>m>>s1>>s2>>s3;
for(int i;i<=n*m;i++){
	cin>>i;
}
if(n==2 and m==2){
	if(s1>s2 and s1>s3 and s1>s4){
		cout<<"1 1";
	}
	if(s1<s2 and s1>s3 and s1>s4){
		cout<<"1 2";
	}
	if(s1<s2 and s1<s3 and s1>s4){
		cout<<"2 2";
	}
	if(s1<s2 and s1<s3 and s1<s4){
		cout<<"2 1";
	}
}


return 0;
}
