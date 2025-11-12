#include<bits/stdc++.h>
using namespace std;
#define l long long
bool cmp(int x,int y){
	return x>y;
}
int a[1000000];
int main(){
	string b;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>b;
	for(l i=0;i<=b.size()-1;i++){
		if(b[i]>='0'&&b[i]<='9'){
			a[i]=b[i];
		}
	}
	sort(a,a+b.size()+1,cmp);
	for(l i=0;i<=b.size()-1;i++){
		if(a[i]-48>=0)	cout<<a[i]-48;
	}
	return 0;
}
