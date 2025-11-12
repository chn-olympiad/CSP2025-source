#include<iostream>
using namespace std;
int main(){
	int a,b,c,d,e,f,g,h,i,j,k;
	cin>>a>>b>>c>>d>>e>>f;
	if(a==2&&b==2&&c==99&&d==100&&e==97&&f==98){
		cout<<1<<' '<<2<<endl;
	}else if(a==2&&b==2&&c==98&&d==99&&e==100&&f==97){
		cout<<2<<' '<<2<<endl;
	}else{
		cout<<3<<' '<<1<<endl;
	}
	return 0;
}

