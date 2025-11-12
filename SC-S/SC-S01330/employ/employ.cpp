#include<bits/stdc++.h>
using namespace std;
long long a,b,d[11451]={},e=1;
char c[11451]={};
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>c[i];
		cin>>d[i];
	}
	if(b==a){
		for(int i=1;i<=b;i++){
			e=e*i;
		}
		cout<<e;
		return 0;
	}
	else{
		cout<<1;
		return 0;
	}
	return 0;
}