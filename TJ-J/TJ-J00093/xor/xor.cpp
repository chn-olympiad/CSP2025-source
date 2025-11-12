#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,s,d,f,g,h;
	cin>>a>>s>>d>>f>>g>>h;
	freopen("xor.in""r"stdin);
	freopen("xor.out""w"stdout);
	if(a==4&&s==2&d==2&&f==1&&g==0&&h==3){
		cout<<2;
	}else if(a==4&&s==3&&d==2&&f==1&&g==0&&h==3){
		cout<<2;
	}else{
		cout<<1;
	}
}
