#include<bits/stdc++.h>
using namespace std;
int a[10005];
int b[10005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=10005;i++){
			if(a[i]>=0 && a[i]<=9){
			cin>>a[i];
		}
	}
	for(int i=1;i<=20;i++){
		cout<<a[i];
	}
	return 0;
}
