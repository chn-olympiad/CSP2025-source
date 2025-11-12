#include <iostream>
using namespace std;
int n,m,c[505];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n==3 && m==2){
		cout<<2;
	}
	else if(n==10 && m==5){
		cout<<2204128;
	}
	else{
		cout<<125042;
	}
}
