#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a,c=0;
	cin>>a;
	int b[1005];
	for(int i=0;i<a;i++){
		cin>>b[i];
		c+=b[i];
	}
	sort(b,b+a);
	if(a<3){
		cout<<0;
	}
	else{
		if(c>b[a-1]*2){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	return 0;
}
