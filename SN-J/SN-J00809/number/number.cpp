//SN-J0809 王锦铭 曲江第二中学 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int s[5],a,b;
	cin>>s[0];
	cout<<s[0];
	a=s[0]/10;
	b=a[0]-a;
	if(a>b or a==b){
		cout<<a<<b;
	}
	if(a<b){
		cout<<b<<a;
	}
	return 0;
}

