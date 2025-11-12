#include<bits/stdc++.h>
using namespace std;
int main(){
	int a;
	cin>>a;
int g=a%10,s=a/10%10,b=a/100%10,q=a/1000%10,w=a/10000%10,sw=a/100000%10;
cout<<g+s*10+b*100+1000*q+w*10000+sw*100000;
int max=g;
	freopen("number.in","r",stdin);
		freopen("number.out","w",stdout);
for(int i;i<7;++i){
if(max<s){
	max=s;
}

	}



return 0;
}
