#include<bits/stdc++.h>
using namespace std;
int a[500];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int m,n;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	int b=1,c=0,d=0;
	d=n+1-m;
	for(int j=1;j<=d;j++){
		for(int i=n;i>=j;i--){
			b=b*i;
		} 
		c=c+b;
		b=1;
	}
	cout<<c;
	
	return 0;
}
