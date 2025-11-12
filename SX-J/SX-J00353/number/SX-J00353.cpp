#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","r",stdout);
	int a,b,c;
	cin>>a>>b>>c;
	for(int i=0;i<=5000;i++){
		if(a<b){
			if(b<c){
				cout<<c<<endl;
			}else{
				cout<<b<<endl;
			}

		}else{
			if(a<c){
				cout<<c<<ennl;
			}else{
				cout<<a<<endl;
			}

		}
	}
}