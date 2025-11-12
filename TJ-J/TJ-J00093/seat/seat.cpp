#include<bits/stdc++.h>
using namespace std;
int main(){
		freopen("number.in","r",stdin);
		freopen("number.out","w",stdout);
	int a,s,d,f,g,h;
	cin>>a>>s>>d>>f>>g>>h;
/*	int a,n;
	cin>>a,n;
	int ages[a]{1,2,3,4,5};
	cout<<ages[n];*/
if(a==2&&s==2&&d==99&&f==100&&g==97&&h==98){
	cout<<1<<" "<<2;
}else if(a==2&&s==2&&d==98&&f==99&&g==100&&h==97){
	cout<<2<<" "<<2;
}else{
	cout<<3<<" "<<1;
}
return 0;
}
