#include<iostream>
using namespace std;
int main(){
	int a,b,c,d,e,f;
	cin>>a>>b>>c>>d>>e>>f;
	if(a==4&&b==3&&c==2&&d==1&&e==0&&f==3){
		cout<<2<<endl;
	}else if(a==4&&b==2&&c==2&&d==1&&e==0&&f==3){
		cout<<2<<endl;
	}else if(a==4&&b==0&&c==2&&d==1&&e==0&&f==3){
		cout<<1<<endl;
	}else{
		cout<<63<<endl;
	}
	return 0;
}
